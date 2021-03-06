#include "digest.h"
#include "common/trinary/trit_tryte.h"

void curl_digest(const trit_t* const trits, size_t len, trit_t* out, Curl* curl){
    char digest[HASH_LENGTH];
    curl_absorb(curl, trits, len);
    curl_squeeze(curl, digest, HASH_LENGTH);
    memcpy((tryte_t*)out,(trit_t*)digest, HASH_LENGTH);
}


