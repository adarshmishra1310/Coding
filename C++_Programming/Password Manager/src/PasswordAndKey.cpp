#include "PasswordAndKey.h"
#include "Cryptography.h"
#include "UUID.h"
#include "Password.h"
#include <iostream>

void add_entry() {
    // prompt label + plaintext
    // derive key = sha256(master_hash + machine_uuid)
    // encrypt, base64, load_store, push, save_store
}
// similarly delete_entry() and list_entries()