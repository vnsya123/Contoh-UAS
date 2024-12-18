import sqlite3

# Fungsi untuk membuat tabel
def create_table():
    connection = sqlite3.connect("matakuliah.db")
    cursor = connection.cursor()
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS Matakuliah (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            kode_mk TEXT NOT NULL,
            nama_mk TEXT NOT NULL,
            sks INTEGER NOT NULL
        )
    """)
    connection.commit()
    connection.close()

# Fungsi untuk menambahkan data
def insert_data(kode_mk, nama_mk, sks):
    connection = sqlite3.connect("matakuliah.db")
    cursor = connection.cursor()
    cursor.execute("INSERT INTO Matakuliah (kode_mk, nama_mk, sks) VALUES (?, ?, ?)", (kode_mk, nama_mk, sks))
    connection.commit()
    connection.close()

# Fungsi untuk menampilkan semua data
def fetch_all_data():
    connection = sqlite3.connect("matakuliah.db")
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM Matakuliah")
    rows = cursor.fetchall()
    connection.close()
    return rows

# Fungsi untuk memperbarui data
def update_data(kode_mk, nama_mk_baru, sks_baru):
    connection = sqlite3.connect("matakuliah.db")
    cursor = connection.cursor()
    cursor.execute("""
        UPDATE Matakuliah
        SET nama_mk = ?, sks = ?
        WHERE kode_mk = ?
    """, (nama_mk_baru, sks_baru, kode_mk))
    connection.commit()
    connection.close()

# Fungsi untuk menghapus data
def delete_data(kode_mk):
    connection = sqlite3.connect("matakuliah.db")
    cursor = connection.cursor()
    cursor.execute("DELETE FROM Matakuliah WHERE kode_mk = ?", (kode_mk,))
    connection.commit()
    connection.close()

# Main program
if __name__ == "__main__":
    # Step 1: Membuat tabel
    create_table()

    # Step 2: Menambahkan 3 data
    insert_data("MK001", "Matematika Teknik", 3)
    insert_data("MK002", "Teknologi Komputer", 3)
    insert_data("MK003", "Logika Matematika", 3)

    # Step 3: Menampilkan semua data
    print("Daftar Mata Kuliah:")
    data = fetch_all_data()
    for row in data:
        print(row)

    # Step 4: Memperbarui data
    update_data("MK002", "Teknologi Komputasi", 4)
    print("\nDaftar Mata Kuliah setelah Update:")
    data = fetch_all_data()
    for row in data:
        print(row)

    # Step 5: Menghapus data
    delete_data("MK003")
    print("\nDaftar Mata Kuliah setelah Hapus:")
    data = fetch_all_data()
    for row in data:
        print(row)
