from flask import Flask, redirect, request, url_for, jsonify, render_template
import sqlite3

app = Flask(__name__)

# Endpoint login
@app.route("/login", methods=['POST'])
def login():
    # Mendapatkan data dari form atau request JSON
    username = request.form.get('username') or request.json.get('username')
    password = request.form.get('password') or request.json.get('password')

    # Validasi login
    if userLogin(username, password):
        return jsonify({"message": "Login successful!", "username": username}), 200
    else:
        return jsonify({"message": "Invalid username or password"}), 401

# Fungsi untuk memvalidasi login
def userLogin(username, password):
    try:
        # Membuka koneksi ke database
        connection = sqlite3.connect("user.db")
        cursor = connection.cursor()
        # Mengeksekusi query untuk memeriksa username dan password
        cursor.execute(
            "SELECT username, password FROM user WHERE username = ? AND password = ?;", 
            (username, password)
        )
        result = cursor.fetchone()
        # Menutup koneksi
        connection.close()
        return result is not None  # Jika ada hasil, berarti login valid
    except sqlite3.Error as e:
        print(f"Database error: {e}")
        return False

# Jalankan aplikasi Flask
if __name__ == '__main__':
    print("This is Flask Program!")
    app.run(debug=True)
