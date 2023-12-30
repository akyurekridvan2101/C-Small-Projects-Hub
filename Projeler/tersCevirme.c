/*
Bir diziyi, boyutu n olan, ters çeviren bir program yazınız.

Örnek: Eğer dizi, arr, ters çevrildikten sonra, dizinin reversed_arr şeklinde olması gerekmektedir.

Giriş Formatı

İlk satır, dizinin boyutunu belirten bir tamsayı olan num'yi içerir.
Sonraki satır, dizinin elemanlarını içeren boşluklarla ayrılmış tamsayıları içerir.

Kısıtlamalar
1 <= num <= 1000, burada arr[i] dizinin i. elemanıdır.

Çıkış Formatı

Çıkış, diziyi yazdıran editördeki kod tarafından ele alınır.

Örnek Giriş 0

6
16 13 7 2 1 12

Örnek Çıkış 0

12 1 2 7 13 16

Açıklama 0

Verilen dizi, arr = {16, 13, 7, 2, 1, 12}. Diziyi ters çevirdikten sonra reversed_arr = {12, 1, 2, 7, 13, 16}.
*/


#include <stdio.h>
#include <stdlib.h>

// Dizi elemanlarını ters çeviren fonksiyon
void tersCevirme(int *dizimiz, int dizi_boyutu) {
    int yedek;
    // Döngü sayısı, dizinin boyutunun yarısı kadar olmalıdır
    int dongu_sayisi = dizi_boyutu / 2;

    // Diziyi baştan ve sondan içeri doğru karşılaştırarak ters çeviren döngü
    for (int donme_sayisi = 1, bastan = 0, sondan = (dizi_boyutu - 1); donme_sayisi <= dongu_sayisi; donme_sayisi++, bastan++, sondan--) {
        // Geçici bir değişken kullanarak elemanları yer değiştir
        yedek = dizimiz[bastan];
        dizimiz[bastan] = dizimiz[sondan];
        dizimiz[sondan] = yedek;
    }
}

int main() {
    int num, *arr, i;
    // Kullanıcıdan dizinin boyutunu al
    scanf("%d", &num);
    // Diziyi dinamik olarak oluştur
    arr = (int *)malloc(num * sizeof(int));

    // Dizinin elemanlarını kullanıcıdan al
    for (i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    // Diziyi ters çevirmek için fonksiyonu çağır
    tersCevirme(arr, num);

    // Ters çevrilen diziyi ekrana yazdır
    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));

    // Ayrılan belleği serbest bırak
    free(arr);

    return 0;
}
