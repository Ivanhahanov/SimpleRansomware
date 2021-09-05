#include "b64.h"
#include "vigenere.h"

std::string encrypt(std::string& msg, std::string& key) {
	std::string b64_str = base64_encode(msg);
	std::string vigenere_msg = encrypt_vigenere(b64_str, key);
	// std::cout << vigenere_msg << std::endl;
	return vigenere_msg;
}