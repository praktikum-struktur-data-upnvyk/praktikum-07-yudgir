// =============================================================================
// SOAL 1a — preorder                                                   20 poin
// =============================================================================
// Contoh:
//
//               50
//              ╱  ╲
//            80    20            preorder(root) mencetak:
//           ╱  ╲     ╲
//         10    70    90             50 80 10 70 30 20 90
//              ╱
//            30
//
//   Coba runut pelan-pelan supaya urutannya masuk akal:
//     50 dicetak dulu (dia root), lalu giliran cabang kirinya;
//     80 dicetak, lalu giliran cabang kirinya;
//     10 dicetak, tidak punya cabang, selesai;
//     70 dicetak, lalu 30 (cabang kirinya), cabang kanannya tidak ada;
//     cabang kiri 50 sudah habis, sekarang cabang kanannya;
//     20 dicetak, cabang kirinya tidak ada, lalu 90.
//
//   Tree kosong tidak mencetak apa pun:
//
//     preorder(NULL);    // layar tidak bertambah apa-apa
//
//   Tree berisi satu node saja mencetak satu angka:
//
//     Node satu{42, NULL, NULL};
//     preorder(&satu);      // mencetak:  42
// =============================================================================
void preorder(const Node* root) {
    if (root == nullptr) return;

    if (root != nullptr) {
        std::cout << (root->data) << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// =============================================================================
// SOAL 1b — inorder                                                    20 poin
// =============================================================================
// Contoh:
//
//               50
//              ╱  ╲
//            80    20            inorder(root) mencetak:
//           ╱  ╲     ╲
//         10    70    90             10 80 30 70 50 20 90
//              ╱
//            30
//
//   Bandingkan dengan preorder yang mencetak  50 80 10 70 30 20 90.
//   Angkanya sama, hanya urutannya yang berpindah. Yang paling kentara: 50
//   tadinya di paling depan, sekarang berada di TENGAH — karena seluruh cabang
//   kirinya harus selesai lebih dulu.
//
//     inorder(NULL);     // tidak mencetak apa pun
// =============================================================================
void inorder(const Node* root) {
    if (root == nullptr) return;
    
    if (root != nullptr) {
        inorder(root->left);
        std::cout << (root->data) << " ";
        inorder(root->right);
    }
}

// =============================================================================
// SOAL 1c — postorder                                                  20 poin
// =============================================================================
// Contoh:
//
//               50
//              ╱  ╲
//            80    20            postorder(root) mencetak:
//           ╱  ╲     ╲
//         10    70    90             10 30 70 80 90 20 50
//              ╱
//            30
//
//   Ketiganya berdampingan supaya bedanya terlihat:
//
//     preorder  : 50 80 10 70 30 20 90     <- 50 di depan
//     inorder   : 10 80 30 70 50 20 90     <- 50 di tengah
//     postorder : 10 30 70 80 90 20 50     <- 50 di belakang
//
//     postorder(NULL);   // tidak mencetak apa pun
// =============================================================================
void postorder(const Node* root) {
    if (root == nullptr) return;

    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        std::cout << (root->data) << " ";
    }
}

// =============================================================================
// SOAL 2b — clear                                                      25 poin
// =============================================================================
// Contoh:
//
//               50
//              ╱  ╲
//            80    20            clear(root);
//           ╱  ╲     ╲
//         10    70    90         sesudahnya:
//              ╱                   root == NULL
//            30                     ketujuh node sudah dibuang dari memori
//
//   Memanggilnya pada tree yang sudah kosong adalah sah:
//
//     Node* root = NULL;
//     clear(root);              // aman, tidak terjadi apa-apa
//
//   Memanggilnya dua kali berturut-turut juga harus aman:
//
//     clear(root);              // tree menjadi kosong
//     clear(root);              // aman, tidak terjadi apa-apa
// =============================================================================
void clear(Node*& root) {
    if (root == nullptr) return;
    clear(root->left);
    clear(root->right);
    delete root;
    root = nullptr;
}

// =============================================================================
// SOAL 3 — jumlahDaun                          SOAL CERITA             15 poin
// =============================================================================
// Contoh:
//
//               50                jumlahDaun(root)  ->  3
//              ╱  ╲
//            80    20             Yang termasuk daun: 10, 30, dan 90.
//           ╱  ╲     ╲
//         10    70    90          Yang BUKAN daun:
//              ╱                    50  punya dua cabang
//            30                      80  punya dua cabang
//                                    20  punya satu cabang (90)
//                                    70  punya satu cabang (30)
//
//   Perhatikan 20 dan 70 baik-baik. Keduanya cuma punya SATU cabang, dan itu
//   tetap membuat mereka BUKAN daun. Daun harus benar-benar tidak punya cabang
//   sama sekali.
//
//   Beberapa keadaan lain:
//
//     Node satu{42, NULL, NULL};
//     jumlahDaun(&satu);        // 1  — dia root sekaligus daun
//     jumlahDaun(NULL);      // 0  — tidak ada orang sama sekali
//
//   Tim yang menjulur lurus ke bawah hanya punya satu daun, yaitu yang paling
//   bawah:
//
//         5
//        ╱
//       4                        jumlahDaun(root)  ->  1
//      ╱                         (hanya node 3; node 5 dan 4 masing-masing
//     3                           masih punya satu cabang)
// =============================================================================
int jumlahDaun(const Node* root) {
    if (root == nullptr) return 0;
    
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    return jumlahDaun(root->left) + jumlahDaun(root->right);
}