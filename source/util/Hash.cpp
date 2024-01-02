#include "util/Hash.h"



Hash::hash_type Hash::hash(const std::uint64_t promoted) noexcept {
    return ((((promoted >> 14) + m_A )  + ((promoted << 54) ^ m_B)) << 4) ^ ((promoted % m_C) * 137);
}

Hash::hash_type Hash::hash(const std::uint32_t value) noexcept {
	const auto promoted = static_cast<std::uint64_t>(value);
	return ((((promoted >> 14) + m_A )  + ((promoted << 54) ^ m_B)) << 4) ^ ((promoted % m_C) * 137);
}

Hash::hash_type Hash::hash(const std::uint16_t value) noexcept {
	const auto promoted = static_cast<std::uint64_t>(value);
    return ((((promoted >> 14) + m_A )  + ((promoted << 54) ^ m_B)) << 4) ^ ((promoted % m_C) * 137);
}

Hash::hash_type Hash::hash(const std::uint8_t value) noexcept {
	const auto promoted = static_cast<std::uint64_t>(value);
    return ((((promoted >> 14) + m_A )  + ((promoted << 54) ^ m_B)) << 4) ^ ((promoted % m_C) * 137);
}

Hash::hash_type Hash::combine_hashes(const hash_type first_hash, const hash_type second_hash) noexcept {
	return first_hash ^ second_hash;
}
