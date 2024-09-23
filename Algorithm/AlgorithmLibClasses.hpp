#ifndef ALGORITHM_LIB_CLASSES_HPP
#define ALGORITHM_LIB_CLASSES_HPP

#include <string>
#include <vector>

template <typename T>
class rabin_karp {
public:
    rabin_karp(const std::string& pattern)
        : pattern(pattern)
        , pattern_length(pattern.length())
        , prime(m_prime) 
    {
        pattern_hash = compute_hash(pattern, pattern_length);
    }

    std::vector<size_t> search(const std::string& text) {
        std::vector<size_t> occurrences;
        size_t text_length = text.length();
        size_t current_hash = compute_hash(text, pattern_length);

        for (size_t i = 0; i <= text_length - pattern_length; ++i) {
            if (current_hash == pattern_hash && text.substr(i, pattern_length) == pattern) {
                occurrences.push_back(i);
            }

            if (i < text_length - pattern_length) {
                current_hash = recalculate_hash(text, current_hash, i, pattern_length);
            }
        }

        return occurrences;
    }

private:
    const size_t m_prime = 101;
    std::string pattern;
    size_t pattern_length;
    size_t prime;
    size_t pattern_hash;

    size_t compute_hash(const std::string& str, size_t length) {
        size_t hash_value = 0;
        for (size_t i = 0; i < length; ++i) {
            hash_value += str[i] * std::pow(prime, length - 1 - i);
        }
        return hash_value;
    }

    size_t recalculate_hash(const std::string& text, size_t old_hash, size_t index, size_t pattern_length) {
        size_t new_hash = old_hash - text[index];
        new_hash /= prime;
        new_hash += text[index + pattern_length] * std::pow(prime, pattern_length - 1);
        return new_hash;
    }
};

#endif // ALGORITHM_LIB_CLASSES_HPP
