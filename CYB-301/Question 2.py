from cryptography.hazmat.primitives import padding, hashes
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
import os

# Step 1: Accept plaintext message from the user
plaintext = input("Enter a message to encrypt: ")

# Step 2: Generate a random 128-bit AES key and 16-byte IV
key = os.urandom(16)  # AES-128 requires a 16-byte key
iv = os.urandom(16)   # Initialization Vector for CBC mode

# Step 3: Pad the plaintext to make it a multiple of 16 bytes
padder = padding.PKCS7(128).padder()  # AES block size = 128 bits
padded_data = padder.update(plaintext.encode()) + padder.finalize()

# Step 4: Encrypt using AES-CBC mode
cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=default_backend())
encryptor = cipher.encryptor()
ciphertext = encryptor.update(padded_data) + encryptor.finalize()

# Step 5: Decrypt the ciphertext
decryptor = cipher.decryptor()
decrypted_padded = decryptor.update(ciphertext) + decryptor.finalize()

# Step 6: Remove padding after decryption
unpadder = padding.PKCS7(128).unpadder()
decrypted_data = unpadder.update(decrypted_padded) + unpadder.finalize()

# Step 7: Display results
print("\n--- AES Encryption Demo ---")
print(f"Original Message: {plaintext}")
print(f"Generated AES Key (hex): {key.hex()}")
print(f"Initialization Vector (IV): {iv.hex()}")
print(f"Encrypted Message (Ciphertext): {ciphertext.hex()}")
print(f"Decrypted Message: {decrypted_data.decode()}")
