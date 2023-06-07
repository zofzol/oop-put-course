#include <thread>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <iostream>

class Counter
{
public:
    explicit Counter(const std::string& section) : section_(section) {}

    void CalculateNoOfNucleotides()
    {
        std::unordered_map<char, int> no_of_nucleotides;

        for (char nucleotide : section_)
        {
            if (nucleotide == 'A' || nucleotide == 'G') 
            {
                ++no_of_nucleotides[nucleotide];
            }
        }

        std::lock_guard<std::mutex> lock(result_mutex_);
        for (const auto& entry : no_of_nucleotides) 
        {
            result_[entry.first] += entry.second;
        }
    }

    static std::unordered_map<char, int> GetResult()
    {
        std::lock_guard<std::mutex> lock(result_mutex_);
        return result_;
    }

private:
    std::string section_;
    static std::unordered_map<char, int> result_;
    static std::mutex result_mutex_;
};

std::unordered_map<char, int> Counter::result_;
std::mutex Counter::result_mutex_;

class DNAScanner 
{
public:
    explicit DNAScanner(const std::string& dna_sequence, int nucleotide_mark)
        : dna_sequence_(dna_sequence), nucleotide_mark_(nucleotide_mark) {}

    void Scan()
    {
        std::vector<std::thread> threads;
        int section_size = dna_sequence_.length() / nucleotide_mark_;

        for (int i = 0; i < nucleotide_mark_; ++i) 
        {
            int start_index = i * section_size;
            std::string section = dna_sequence_.substr(start_index, section_size);

            threads.emplace_back([section]() 
            {
                Counter counter(section);
                counter.CalculateNoOfNucleotides();
            });
        }

        for (auto& thread : threads) 
        {
            if (thread.joinable()) 
            {
                thread.join();
            }
        }

        std::unordered_map<char, int> result = Counter::GetResult();
        for (const auto& entry : result) 
        { std::cout << entry.first << ": " << entry.second << std::endl;}
    }

private:
    std::string dna_sequence_;
    int nucleotide_mark_;
};

int main() 
{
    std::string dna_sequence = "ACGTTGGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTGAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAGCTAG";
    int nucleotide_mark = 4;

    DNAScanner scanner(dna_sequence, nucleotide_mark);
    scanner.Scan();

    return 0;
}

