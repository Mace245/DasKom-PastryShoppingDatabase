#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct reguler {
    char nama[20], id[20], pass[20], telp[20], bolu1[10], bolu2[10], bolu3[10], bolu4[10], bolu5[10], kota[15];
    int total;
}r;

struct premium {
    char nama[20], id[20], pass[20], telp[20], bolu1[10], bolu2[10], bolu3[10], bolu4[10], bolu5[10], kota [15];
    int total;
    int vouch;
}p;

struct bolu {
    char bolu[10], harga[10];
}b;

struct kota {
    char kota[10];
}k;

void registerp();
int login();

void reguler();
void premium();

void apusdata();
void simpanPesanan();
void hitungVoucher();
void cari();

void readPesanan();

void tambahBolu();
void readBolu();

void tambahKota();
void readKota();

FILE *user;
FILE *bolu;

void main() {
    int entry;

    system ("cls");
    printf("--Menu Utama-- \n1. Login \n2. Register \n3. Berhentikan D'pastry \nPilih: ");
    scanf("%d", &entry); getchar();
    switch(entry) {
        case 1: system ("cls");
                login(1);
                break;

        case 2: registerp();
                break;

        case 3: break;
    }
}


void registerp() {
    char nama[20], telp[20], id[20], pass[20];
    int tipe, vouch;
    FILE *registrasi;

    system ("cls");

    printf("Masukkan tipe akun yang diinginkan: \n1. Reguler \n2. Premium");
    scanf("%d", &tipe); getchar();

    switch(tipe) {

        case 1: registrasi = fopen("Reguler.dat", "ab");

                printf("Masukkan nama: "); // help
                gets(r.nama);
                printf("Masukkan nomor telepon: ");
                gets(r.telp);
                printf("Masukkan id: ");
                gets(r.id);
                printf("Masukkan password: ");
                gets(r.pass);
                fwrite(&r, sizeof (r), 1, registrasi);

                fclose(registrasi);
                break;

       case 2 : registrasi = fopen("Premium.dat", "ab");

                printf("Masukkan nama: "); // help
                gets(p.nama);
                printf("Masukkan nomor telepon: ");
                gets(p.telp);
                printf("Masukkan id: ");
                gets(p.id);
                printf("Masukkan password: ");
                gets(p.pass);
                fwrite(&p, sizeof (p), 1, registrasi);

                fclose(registrasi);
                break;
    }
    main();
}


int login(int percobaan) {
    int acc;

    printf("===SELAMAT DATANG DI D'PASTRY SILAHKAN LOGIN \n Tipe akun yang ingin digunakan: \n 1. Reguler \n 2. Premium \n 3. Admin");
    scanf("%d", &acc); fflush(stdin);
    switch(acc) {
        case 1: reguler();
                break;

        case 2: premium();
                break;

        case 3: admin();
                break;
    }
/*
    printf("   ID : ");
    gets(id);
    printf("   Password : ");
    gets(pass);
    while(fread(&a,sizeof(a),1,registrasi)==1){
        if(strcmp(id, a.id)==0 && strcmp(pass, a.pass)==0) {
            tipe = 1;
            }
    }



    while(fread(&p,sizeof(p),1,registrasi)==1){

        if(strcmp(id, p.id)==0 && strcmp(pass, p.pass)==0) {
            printf("Selamat datang premium!");
            tipe = 3;
        }
    }

    switch(tipe) {
        case 1: admin();
                break;

        case 2: reguler();
                break;

        case 3: premium();
                break;

        default: printf("ID/Password salah atau akun belum terdaftar\n\n");
                 percobaan++;
                 if (percobaan < 4) login(percobaan);
                 break;

    }
    fclose(registrasi);
    */
}


void reguler(){
    int no_struct;
    long int offset_byte;
    char boluTambah[15], hargaTambah[15], ret[5];
    bolu = fopen("daftarbolu.dat", "rb");
    int i;

    int try=0;
    char id[20], pass[20];
    user = fopen("Reguler.dat", "rb");

    system("cls");
    start:

    if(try < 3){
        printf("Reguler Login\n   ID : ");
        gets(id);
        printf("   Password : ");
        gets(pass);
        while(fread(&r,sizeof(r),1,user)==1){
            if(strcmp(id, r.id)==0 && strcmp(pass, r.pass)==0) {
            printf("Selamat datang pengguna akun reguler!\n");
            }
        }
    }
    else {
        printf("\nToo many tries");
        exit(1);
    }

    start2:

    readPesanan();

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }
    fseek(bolu,0,SEEK_SET);


    printf("Silahkan ketik item yang diinginkan pada menu: ");
    gets(boluTambah);

    printf("uwu");

    while(fread(&b,sizeof(b),1,bolu)==1){
            if(strcmp(boluTambah, b.bolu)==0) {
                printf("Menu\t: %s\n", b.bolu);
                printf("Harga\t: %d\n", b.harga);
                strcpy(r.bolu1, b.bolu);
                r.total =+ atoi(b.harga);
                readPesanan();
                fwrite (&r, sizeof (r), 1, user);
                printf("Penambahan pesanan berhasil\n\n");
                break;
            }
            else {
                printf("Item tersebut tidak ada pada menu\n\n");
            }
        }

   /* if (fread(&b, sizeof(b), 1, bolu) == 0) {
        printf("Menu yang dicari tidak dapat ditemukan pada b.\n");
    }
    else {
        printf("Menu\t: %s\n", b.bolu);
        printf("Harga\t: %d\n", b.harga);
        if (r.bolu1!=NULL){
            strcpy(b.bolu, r.bolu1);
            printf("Penambahan pesanan berhasil\n");
        }
    }*/
    printf("Return to Main Menu? (yes/no)");
    gets(ret);
    if(strcmp(ret,"yes"==0)) {main();}
    else {
        system("cls");
        goto start2;
    }

    fclose(bolu);

}

    void hitungVoucher() {


    }

    void simpanPesanan(){


	}



void premium(){

struct{
    char bolu[10];
    int harga;
}b;

struct{
    char nama[50], userid[50], password[50],nomortelfon[50], bolu[9];
}a;

    FILE *data;
    int no_struct;
    long int offset_byte;
    char boluTambah[15], hargaTambah[15];
    data = fopen("daftarbolu.dat", "rb");
    int i, pesanan;

    FILE *bolu;
    bolu = fopen("daftarBolu.dat", "rb");

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    fclose(bolu);
	    printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
    scanf("%d", &no_struct);
    	offset_byte = (no_struct - 1) * sizeof(b);
    	fseek(data, offset_byte, SEEK_SET);

    if (fread(&b, sizeof(b), 1, data) == 0)
    {
        printf("Menu yang dicari tidak dapat ditemukan pada b.\n");
    }
    else
    {
        printf("Menu\t: %s\n", b.bolu);
        printf("Harga\t: %d", b.harga);
        pesanan = no_struct;
        strcpy(boluTambah, b.bolu);
    }
    fclose(data);
    void simpanPesanan(){


	}
}


void admin() {
    int aksi, try=0;
    char id[20], pass[20];
    FILE *registrasi;

    system("cls");
    start:

    if(try < 3){
    printf("Admin Login\n   ID : ");
    gets(id);
    printf("   Password : ");
    gets(pass);
        if(strcmp(id, "")==0 && strcmp(pass, "a")==0) {
            printf("Login berhasil!");
            }
            else {
                try++;
                goto start;
            }
    }
    else {
        printf("\nToo many tries");
        exit(1);
    }

    registrasi = fopen("Program Registrasi.dat", "rb");

    afterLog:
    system("cls");

    printf("Selamat datang Admin!\n");

       /* for (int i=0;i>=0;i++)
                for (int j=1;j<=i;j++) {
                    if (strlen(a[j-1].nama) > strlen(a[j].nama)) {
                        temp=a[j-1];
                        a[j-1]=a[j];
                        a[j]=temp;
                    }
                }*/
    int i=0;
    char balik[10];

    printf("\nAkun reguler: \n");
    while(fread(&r,sizeof(r),1,registrasi)==1) {
        printf("%d. %s\n", i+1, r.nama);
        i++;
    }
    if(i==0) printf("Tidak ada akun yang terdaftar\n");
    i=0;

    printf("\nAkun premium: \n");
    while(fread(&p,sizeof(p),1,registrasi)==1) {
        printf("%d. %s\n", i+1, p.nama);
        i++;
    }
    if(i==0) printf("Tidak ada akun yang terdaftar\n");
    fclose(registrasi);

    readBolu();

    printf("\nMenu aksi: \n 1. Tambah jenis kue\n 2. Tambah Kota\n 3. Kasih voucher\n 4. Hapus akun \n 5. Balik ke menu utama");
    scanf("%d", &aksi); getchar();

    switch(aksi) {
    case 1: tambahBolu();
            readBolu();
            break;

    case 2: tambahKota();
            break;

    case 3: tambahVoucher();
            break;

    case 4: //hapusAkun()
            break;

    case 5: main();
            break;
    }

    printf("\nBalik ke menu admin? (iya/tidak)");
    gets(balik);
    if (strcmp(balik,"iya")==0)
        goto afterLog;
    else main();
}


void apusdata(){
    FILE *pesanan;
    FILE *pesanan2;

    char dicari[50];
    struct {
        char bolu[30];
    } order;
    struct{
    char bolu[10];
    }daftar;

    pesanan = fopen("Pesanan.dat", "rb");
    pesanan2 = fopen("Pesanan2.dat", "wb");
    printf("Silahkan masukkan pesanan bolu yang ingin dihapus: "); gets(dicari);
    while (fread(&daftar,sizeof (daftar),1, pesanan)==1){
        if (strcmp(order.bolu, dicari)!=0){
        fwrite(&order, sizeof(order), 1, pesanan2);
        }
    }
    fclose(pesanan);
    fclose(pesanan2);
    remove("Pesanan.dat");
    rename("Pesanan2.dat","Pesanan.dat");
    printf("pesanan telah dihapus");
}


void cari(){
	FILE *f_struktur;
    int no_struct;
    long int offset_byte;
    void rewind(FILE *stream);

    struct {
    char Menu [30];
    double Harga;
    } daftar;
    f_struktur = fopen("Daftar Harga.dat", "rb");
    printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
    scanf("%d", &no_struct);
    offset_byte = (no_struct - 1) * sizeof(daftar);
    fseek(f_struktur, offset_byte, SEEK_SET);
    if (fread(&daftar, sizeof (daftar), 1, f_struktur) == 0){
    printf("Menu yang dicari tidak dapat ditemukan pada daftar.\n");
    } else {
        printf("Menu : %s\n",daftar.Menu);
        printf("Harga: %lf\n",daftar.Harga);
    }
    fclose(f_struktur);
}


void readPesanan(){
    printf("\nDaftar pesanan: \n", r.bolu1);
    printf("1. %s\n", r.bolu1);
    printf("2. %s\n", r.bolu2);
    printf("3. %s\n", r.bolu3);
    printf("4. %s\n", r.bolu4);
    printf("5. %s\n", r.bolu5);
    printf("Total: %d\n\n", r.total);
}

void tambahBolu() {
    FILE *fb;
    fb = fopen("daftarBolu.dat", "ab");

    int i, n;

    printf("Masukkan jumlah kue yang ingin ditambahkan: ");
    scanf("%d", &n); fflush(stdin);

    for(i=0;i<n;i++) {
    printf("Silahkan masukkan nama bolu yang ingin ditambah ke dalam daftar: ");
    gets(b.bolu);
    printf("Silahkan masukkan harga bolu yang ingin ditambah ke dalam daftar: ");
    gets(b.harga);
    fwrite (&b, sizeof (b), 1, fb);
    }

    fclose(fb);
}


void readBolu() {
    FILE *fb;
    fb = fopen("daftarBolu.dat", "rb");
    int i;

    printf("Daftar Pesanan: \n");
    while(fread(&b,sizeof(b),1,fb)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }
    fclose(fb);
}


void tambahKota() {
    FILE *f_kota;
    f_kota = fopen("daftarKota.dat", "ab");

    int i, n;
    char balik[10];

    printf("Masukkan jumlah kota yang ingin ditambahkan: ");
    scanf("%d", &n); getchar();

    for(i=0;i<n;i++) {
    printf("Silahkan masukkan nama kota yang ingin ditambah ke dalam daftar: ");
    gets(k.kota);
    fwrite (&k, sizeof (k), 1, f_kota);
    }

    fclose(f_kota);

    printf("\nPenambahan berhasil! \nDaftar kota: \n");
    readKota();
}


void readKota() {
    int i;
    FILE *f_kota;
    f_kota = fopen("daftarKota.dat", "rb");

    while(fread(&k,sizeof(k),1,f_kota)==1){
        i++;
        printf("%d. %s\n", i, k.kota);
    }
    fclose(f_kota);
}


void tambahVoucher() {
    int id;
    FILE *registrasi;
    registrasi = fopen("Program Registrasi.dat", "rb");

    system("cls");

    printf("--Menu Tambah Voucher--\n\n");
    printf("Masukkan id akun yang ingin ditambahkan voucher: ");
    scanf("%d", &id);

    while(fread(&p,sizeof(p),1,registrasi)==1) {
        if(strcmp(id, p.id)==0) break;
            printf("Nama: %s\n", p.nama);
            printf("ID: %s\n", p.id);
    }
    fclose(registrasi);
}
