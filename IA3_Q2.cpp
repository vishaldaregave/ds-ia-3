#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>

namespace
{
constexpr int kTableSize = 29;
constexpr std::array<int, 20> kDataset{
    60, 73, 86, 99, 12, 25, 38, 51, 64, 77,
    90, 3, 16, 29, 42, 55, 68, 81, 94, 7};

int divisionHash(int key)
{
    return key % kTableSize;
}

class HashTable
{
public:
    HashTable() : slots_(kTableSize, -1) {}

    bool insertKey(int key)
    {
        if (key < 0)
        {
            std::cout << "Invalid key " << key
                      << ". Negative values are not allowed.\n";
            return false;
        }

        if (std::find(slots_.begin(), slots_.end(), key) != slots_.end())
        {
            std::cout << "Duplicate key " << key << " ignored.\n";
            return false;
        }

        int index = divisionHash(key);
        std::cout << "Inserting " << key << " | Hash index = " << index;

        for (int probes = 0; probes < kTableSize; ++probes)
        {
            if (slots_[index] == -1)
            {
                slots_[index] = key;
                ++insertedCount_;
                std::cout << " | Inserted at index " << index << '\n';
                return true;
            }

            ++collisionCount_;
            std::cout << " | Collision at index " << index;
            index = (index + 1) % kTableSize;
        }

        std::cout << " | Hash table is full; " << key
                  << " was not inserted.\n";
        return false;
    }

    void displayInsertionStatistics(std::size_t totalInputValues) const
    {
        const int occupiedPositions = insertedCount_;
        const int emptyPositions = kTableSize - occupiedPositions;
        const double loadFactor =
            static_cast<double>(occupiedPositions) / kTableSize;

        std::cout << "\n========== INSERTION SUMMARY ==========\n"
                  << "Total input values: " << totalInputValues << '\n'
                  << "Successfully inserted: " << insertedCount_ << '\n'
                  << "Total collisions: " << collisionCount_ << '\n'
                  << "Occupied positions: " << occupiedPositions << '\n'
                  << "Empty positions: " << emptyPositions << '\n'
                  << "Load factor: " << std::fixed << std::setprecision(4)
                  << loadFactor << '\n';
    }

    void displayTable() const
    {
        std::cout << "\n========== FINAL HASH TABLE ==========\n"
                  << "Index\tValue\n";

        for (int index = 0; index < kTableSize; ++index)
        {
            std::cout << index << '\t';
            if (slots_[index] == -1)
            {
                std::cout << "Empty";
            }
            else
            {
                std::cout << slots_[index];
            }
            std::cout << '\n';
        }
    }

private:
    std::vector<int> slots_;
    int collisionCount_ = 0;
    int insertedCount_ = 0;
};
} // namespace

int main()
{
    HashTable hashTable;

    std::cout << "DATA STRUCTURES IA 3 - QUESTION 2\n"
              << "Student: Vishal Daregave\n"
              << "PRN: 202501100056\n"
              << "Scenario: Mango Varieties\n"
              << "Personalization: v[i] = (60 + 13*i) % 100\n"
              << "Hash Function: h(key) = key % " << kTableSize << '\n'
              << "Collision Handling: Linear Probing\n"
              << "Table Size: " << kTableSize << "\n\n"
              << "Personalized Dataset:\n";

    for (const int value : kDataset)
    {
        std::cout << value << ' ';
    }

    std::cout << "\n\n========== INSERTION PROCESS ==========\n";
    for (const int value : kDataset)
    {
        hashTable.insertKey(value);
    }

    std::cout << "\n========== DUPLICATE KEY TEST ==========\n";
    hashTable.insertKey(60);

    std::cout << "\n========== INVALID KEY TEST ==========\n";
    hashTable.insertKey(-10);

    hashTable.displayInsertionStatistics(kDataset.size());
    hashTable.displayTable();
    return 0;
}
