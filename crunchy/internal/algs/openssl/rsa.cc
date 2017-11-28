// Copyright 2017 The CrunchyCrypt Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "crunchy/internal/algs/openssl/rsa.h"

namespace crunchy {

StatusOr<std::string> SerializePrivateKey(const RSA* rsa) {
  uint8_t* serialized_private_key = nullptr;
  size_t serialized_private_key_length;
  if (RSA_private_key_to_bytes(&serialized_private_key,
                               &serialized_private_key_length, rsa) != 1) {
    return InternalErrorBuilder(CRUNCHY_LOC).LogInfo()
           << "Openssl internal error serializing private key: "
           << GetOpensslErrors();
  }
  std::string result(reinterpret_cast<char*>(serialized_private_key),
                serialized_private_key_length);
  OPENSSL_free(serialized_private_key);
  return result;
}

StatusOr<openssl_unique_ptr<RSA>> DeserializePrivateKey(
    absl::string_view serialized_private_key) {
  openssl_unique_ptr<RSA> rsa(RSA_private_key_from_bytes(
      reinterpret_cast<const uint8_t*>(serialized_private_key.data()),
      serialized_private_key.size()));
  if (rsa == nullptr) {
    return InternalErrorBuilder(CRUNCHY_LOC).LogInfo()
           << "Openssl internal error parsing private key: "
           << GetOpensslErrors();
  }
  return std::move(rsa);
}

StatusOr<std::string> SerializePublicKey(const RSA* rsa) {
  uint8_t* serialized_public_key = nullptr;
  size_t serialized_public_key_length;
  if (RSA_public_key_to_bytes(&serialized_public_key,
                              &serialized_public_key_length, rsa) != 1) {
    return InternalErrorBuilder(CRUNCHY_LOC).LogInfo()
           << "Openssl internal error serializing public key: "
           << GetOpensslErrors();
  }
  std::string result(reinterpret_cast<char*>(serialized_public_key),
                serialized_public_key_length);
  OPENSSL_free(serialized_public_key);
  return result;
}

StatusOr<openssl_unique_ptr<RSA>> DeserializePublicKey(
    absl::string_view serialized_public_key) {
  openssl_unique_ptr<RSA> rsa(RSA_public_key_from_bytes(
      reinterpret_cast<const uint8_t*>(serialized_public_key.data()),
      serialized_public_key.size()));
  if (rsa == nullptr) {
    return InternalErrorBuilder(CRUNCHY_LOC).LogInfo()
           << "Openssl internal error parsing public key: "
           << GetOpensslErrors();
  }
  return std::move(rsa);
}

}  // namespace crunchy
