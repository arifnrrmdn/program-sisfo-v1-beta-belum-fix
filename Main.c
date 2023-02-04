#include <stdio.h>

//deklarasi fungsi
void showMenu();
void inputData();
void bisnisLogic();
void output();

//deklarasi struct
struct opsi{
    int pilih,ambil,kembali;
}ops;

struct total{
    int total_sewa,total_jasa,total_semua;
}ttl;

//deklarsi variabel
char sopir,TM,minibus;
int biaya_sewa,biaya_sopir,makan,waktu,overtime;



int main() {
    showMenu();
    inputData();
    bisnisLogic();
    output();
    return 0;
}

//defnisi fungsi
void showMenu(){
    puts("Rental Mobil \"SISFO\"");
    puts("====================");
    puts("Tipe Mobil Yang Tersedia");
    puts("1. Minibus	Rp 350000");
    puts("2. Sedan	Rp 400000");
    puts("3. MPV		Rp 450000");
    puts("4. SUV		Rp 550000");
    puts("*harga per 12 jam");
}

void inputData(){
    printf("Tipe Mobil yang dipilih = "); scanf("%d", &ops.pilih);
    printf("Menggunakan jasa sopir [Y/N] = "); scanf("%s",&sopir);
    printf("Waktu pengambilan   = "); scanf("%d",&ops.ambil);
    printf("Waktu pengembalian  = "); scanf("%d",&ops.kembali);
}

void bisnisLogic(){

    //pilih jenis mobil
    if (ops.pilih == 1) {
        biaya_sewa=350000;
    }else if(ops.pilih == 2) {
        biaya_sewa=400000;
    }else if(ops.pilih == 3) {
        biaya_sewa=450000;
    }else if(ops.pilih == 4) {
        biaya_sewa=550000;
    }else{
        printf("Input Salah");
    }

    //sopir
    if(sopir=='y' || sopir=='Y'){
        biaya_sopir = 150000;
        makan = 50000;
    }else{
        biaya_sopir = 0;
        makan = 0;
    }

    //menghitung total
    if(ops.kembali>ops.ambil){
        waktu = ops.kembali-ops.ambil;

        if(waktu%12==0){
            ttl.total_sewa = waktu % 12;
            ttl.total_jasa = biaya_sopir + makan;
            ttl.total_semua = ttl.total_jasa + ttl.total_sewa;
        }
        if(waktu%12!=0){
            makan=70000;
            overtime=waktu%12;
            ttl.total_sewa=overtime*(biaya_sewa*0.1)+(waktu-overtime)/12*biaya_sewa;
            ttl.total_jasa = biaya_sopir + makan;
            ttl.total_semua = ttl.total_sewa + ttl.total_jasa;
        }

    }

    if(ops.ambil>=ops.kembali){
        waktu = (24-ops.ambil) + ops.kembali;

        if(waktu%12==0){
            ttl.total_sewa = waktu % 12;
            ttl.total_jasa = biaya_sopir + makan;
            ttl.total_semua = ttl.total_jasa + ttl.total_sewa;
        }
        if(waktu%12!=0){
            makan=70000;
            overtime=waktu%12;
            ttl.total_sewa=overtime*(biaya_sewa*0.1)+(waktu-overtime)/12*biaya_sewa;
            ttl.total_jasa = biaya_sopir + makan;
            ttl.total_semua = ttl.total_sewa + ttl.total_jasa;
        }

    }

}

void output(){
    printf("Total biaya sewa            = %d\n",ttl.total_sewa);
    printf("Total biaya jasa            = %d\n",ttl.total_jasa);
    printf("Total yang harus dibayar    = %d\n",ttl.total_semua);
}


