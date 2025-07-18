#include <tsugou/utils.hpp>

#include <openssl/evp.h>
#include <openssl/sha.h>

namespace tsugou {
String bytes_to_hex_string(const Vector<u8> &bytes) {
  std::ostringstream stream;
  for (u8 b : bytes) {
    stream << std::setw(2) << std::setfill('0') << std::hex
           << static_cast<int>(b);
  }
  return stream.str();
}

String sha3_256(const String &input) {
  uint32_t digest_length = SHA256_DIGEST_LENGTH;
  const EVP_MD *algorithm = EVP_sha3_256();
  u8 *digest = static_cast<u8 *>(OPENSSL_malloc(digest_length));
  EVP_MD_CTX *context = EVP_MD_CTX_new();
  EVP_DigestInit_ex(context, algorithm, nullptr);
  EVP_DigestUpdate(context, input.c_str(), input.size());
  EVP_DigestFinal_ex(context, digest, &digest_length);
  EVP_MD_CTX_destroy(context);
  String output =
      bytes_to_hex_string(Vector<u8>(digest, digest + digest_length));
  OPENSSL_free(digest);
  return output;
}

} // namespace tsugou