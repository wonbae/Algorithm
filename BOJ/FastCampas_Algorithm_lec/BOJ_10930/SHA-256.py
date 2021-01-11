import hashlib
input_data = input()
encoded_data = input_data.encode()
res = hashlib.sha256(encoded_data).hexdigest()
print(res)