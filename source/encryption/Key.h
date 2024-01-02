#pragma once

#include <array>
#include <cstdint>
#include <span>

class Key {
public:
	using key_type = std::array<std::uint8_t, 48>;

	[[nodiscard]] static key_type get_standard_key() noexcept;
    [[nodiscard]] static key_type produce_new_key(key_type keyType) noexcept;
    [[nodiscard]] static std::uint64_t hash(key_type keyType) noexcept;
    [[nodiscard]] static std::uint64_t get_smallest_hash(std::span<key_type const> range) noexcept;

    [[nodiscard]] static std::uint64_t get_smallest_hash_parallel(std::span<key_type const> range, int thread_count) noexcept;




private:

};
