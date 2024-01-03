#include <iostream>
#include <bitset>
#include "encryption/Key.h"
#include "util/Hash.h"
#include <numeric>
#include <format>

Key::key_type Key::get_standard_key() noexcept {
	auto key = key_type{};
	for (auto i = key_type::value_type(0); i < key.size(); i++) {
		key[i] = i;
	}

	return key;
}

Key::key_type Key::produce_new_key(Key::key_type keyType) noexcept {
    for (auto i = 0; i < 6; i++) {
        auto to_hash = uint64_t{};
        for(auto j = 0; j < 8; j++) {
            uint64_t number = keyType[i * 8 + j];
            number <<= j * 8;
            to_hash |= number;

        }
        //std::cout << std::bitset<64>(to_hash) << "\n";
        auto hashed = Hash::hash(to_hash);
        for (auto j = 0; j < 8; j++) {
            keyType[i * 8 + j] = hashed;
            hashed >>= 8;
        }
    }
    return keyType;
}

std::uint64_t Key::hash(Key::key_type keyType) noexcept {

    std::uint64_t combined = 0;
    for(auto i = 0; i < 6; i++) {
        std::uint64_t to_hash = 0;
        for(auto j = 0; j < 8; j++) {
            uint64_t number = keyType[i * 8 + j];
            number <<= j * 8;
            to_hash |= number;//to_hash += ((std::uint64_t)0x01) << 56;

        }
        //std::cout << "\n\n";
        combined = Hash::combine_hashes(combined, Hash::hash(to_hash));
        //std::cout << "PRE_" << std::bitset<64>(Hash::hash(to_hash))<< "\n" << "COM_" << std::bitset<64>(combined) << "\n\n";


    }
    return combined;
}

std::uint64_t Key::get_smallest_hash(std::span<key_type const> range) noexcept {
    auto min = std::numeric_limits<std::uint64_t>::max();
    for(auto key_type : range) {

        auto val = hash(key_type);
        std::string s = std::format("{:x}", val);
        std::cout << s << "\n";
        if(val < min){

            std::cout << "Overwrite: " << std::format("{:x}", val) << "<" << std::format("{:x}", min) << "\n";
            min = val;
        }
    }
    return min;
}

std::uint64_t Key::get_smallest_hash_parallel(std::span<const key_type> range, int thread_count) noexcept {
    return uint64_t {};
}
