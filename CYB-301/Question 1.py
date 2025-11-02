import random
from math import gcd

# ---------- Helper Functions ----------

def is_probable_prime(n, k=5):
    """Miller-Rabin primality test"""
    if n < 2:
        return False
    # Check small primes
    for p in [2, 3, 5, 7, 11, 13, 17, 19, 23]:
        if n % p == 0:
            return n == p

    # Write n-1 as 2^r * d
    r, d = 0, n - 1
    while d % 2 == 0:
        r += 1
        d //= 2

    # Perform k rounds of testing
    for _ in range(k):
        a = random.randrange(2, n - 2)
        x = pow(a, d, n)
        if x in (1, n - 1):
            continue
        for __ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True


def generate_large_prime(bits=8):
    """Generate a random prime number with the given bit length"""
    while True:
        num = random.getrandbits(bits)
        num |= (1 << bits - 1) | 1  # Ensure it's odd and has correct bit length
        if is_probable_prime(num):
            return num


def mod_inverse(e, phi):
    """Compute modular inverse using Extended Euclidean Algorithm"""
    def egcd(a, b):
        if b == 0:
            return a, 1, 0
        g, x1, y1 = egcd(b, a % b)
        return g, y1, x1 - (a // b) * y1

    g, x, _ = egcd(e, phi)
    if g != 1:
        raise Exception("Modular inverse does not exist")
    return x % phi


# ---------- RSA Key Generation ----------

def generate_keys(bits=8):
    p = generate_large_prime(bits)
    q = generate_large_prime(bits)
    while q == p:
        q = generate_large_prime(bits)

    n = p * q
    phi = (p - 1) * (q - 1)

    e = random.randrange(2, phi)
    while gcd(e, phi) != 1:
        e = random.randrange(2, phi)

    d = mod_inverse(e, phi)

    return (n, e), (n, d)


# ---------- Encryption and Decryption ----------

def encrypt(message, public_key):
    n, e = public_key
    cipher = [pow(ord(char), e, n) for char in message]
    return cipher


def decrypt(cipher, private_key):
    n, d = private_key
    plain = ''.join([chr(pow(c, d, n)) for c in cipher])
    return plain


# ---------- Main Program ----------

def main():
    print("=== RSA Encryption & Decryption Demo ===")

    public_key, private_key = generate_keys(bits=8)
    print(f"\nPublic Key (n, e): {public_key}")
    print(f"Private Key (n, d): {private_key}")

    message = input("\nEnter a message to encrypt: ")
    cipher = encrypt(message, public_key)
    print("\nEncrypted Message (Ciphertext):", cipher)

    decrypted = decrypt(cipher, private_key)
    print("\nDecrypted Message:", decrypted)


if __name__ == "__main__":
    main()
