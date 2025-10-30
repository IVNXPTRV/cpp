#!/bin/bash

# --- Configuration ---
PHONEBOOK_CMD="./phonebook"

# --- Input Data Generation ---
# Generates the command sequence and pipes it to the phonebook program.
# The \n ensures each piece of data is treated as a separate input line.
# Note: Input data is fictional and designed to test proper formatting.

INPUT_DATA=$(cat << EOF
ADD
Jane
Austen
JA
101223344
Loves old books
ADD
Leo
Tolstoy
Count
202334455
Wrote too much
ADD
Mark
Twain
MT
303445566
Was a river pilot
ADD
Virginia
Woolf
VW
404556677
Loved the waves
ADD
Ernest
Hemingway
Papa
505667788
Fears the sea
ADD
George
Orwell
GO
606778899
Watches everyone
ADD
Ayn
Rand
AR
707889900
Admires herself
ADD
Franz
Kafka
FK
808990011
Feels buggy
ADD
Theodore
Roosevelt
Teddy
4242424242
Doesnt like bears
SEARCH
0
SEARCH
2
SEARCH
-5
SEARCH
9
1
ADD
Ivan
Petrov
IVNXPTRV
1234
wwwwwwww
SEARCH
0
EXIT
EOF
)

echo "--- Initializing 8 Contacts ---"

# Pipe the generated multi-line input data directly to the executable
echo "$INPUT_DATA" | "$PHONEBOOK_CMD"

echo "--- Initialization Complete (Program Exited) ---"
