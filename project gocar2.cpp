#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

	void menu();
	void tampil_data();
	void tambah_data();
	void edit_data();
	void hapus_data();
	void close();
	void header();
		
		struct data{
			char nama[99];
			char mitra[50];
			char merk_kendaraan[50];
			char type_kendaraan[50];
			char transmisi[50];
			int id;
			int kapasitas_mesin, tahun;
			char warna[50];
			char plat[50];
			char area[99];
		}tambah, cek, hapus, temp;
		
		char index[2];
		struct date{
			int tgl;
			int bln;
			int thn;
		};
		int main()
		{
			system("cls");
				printf("Now Loading");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
				Sleep(500);
				printf(". ");
			menu();
			return 0;
		}
		
			void menu(){
				int pilih;
					menu:
						system("cls");
							header();
							printf("\t\tAplikasi Data Driver Gocar\n\n");
							printf("\t[1]Tampilkan Data Driver\n");
							printf("\t[2]Tambahkan Data Driver\n");
							printf("\t[3]Edit Data Driver\n");
							printf("\t[4]Hapus Data Driver\n");
							printf("\t[8]Keluar\n\n");
							printf("\t\tMasukan Nomor Yang Dipilih : ");
							scanf("%d", &pilih);
							
								switch(pilih){
									case 1 : tampil_data();
										break;
									case 2 : tambah_data();
										break;
									case 3 : edit_data();
										break;
									case 4 : hapus_data();
										break;
									case 8 : close();
										break;
									default:printf("\nMohon Maaf Pilihan Anda Salah !");
									getche();
									goto menu;
								}
							
				
			}
			
			void tambah_data(){
				FILE *ptr,*ptr1;
					int count=0;
						ptr =fopen("datadriver.txt","a");
							system("cls");
							ptr1 =fopen("datadriver.txt","r");
							while(fscanf (ptr1,"%d;%[^\n];%[^\n];%[^\n];%[^\n];%[^\n];%d;%[^\n];%d;%[^\n];%[^\n]\n"
							,&tambah.id,tambah.nama,tambah.mitra,tambah.merk_kendaraan,tambah.type_kendaraan,tambah.transmisi,&tambah.kapasitas_mesin,tambah.warna,&tambah.tahun,tambah.plat,tambah.area)!=EOF)
							{
								tambah.id++;
							}
							cek.id = tambah.id;
							fclose(ptr1);
							printf ("masukan nama driver : ");fflush(stdin);
							scanf ("%[^\n]",tambah.nama);
							printf ("masukan nama mitra : ");fflush(stdin);
							scanf ("%[^\n]",tambah.mitra);
							printf ("masukan merk kendaraan : ");fflush(stdin);
							scanf ("%[^\n]",tambah.merk_kendaraan);
							printf ("masukan type kendaraan : ");fflush(stdin);
							scanf ("%[^\n]",tambah.type_kendaraan);
							printf ("masukan transmisi : ");fflush(stdin);
							scanf ("%[^\n]",tambah.transmisi);
							printf ("masukan kapasitas menis : ");
							scanf ("%d",&tambah.kapasitas_mesin);
							printf ("masukan warna kendaraan : ");fflush(stdin);
							scanf ("%[^\n]",tambah.warna);
							printf ("masukan tahun kendaraan : ");
							scanf ("%d",&tambah.tahun);
							printf ("masukan plat nomor kendaraan : ");fflush(stdin);
							scanf ("%[^\n]",tambah.plat);
							printf ("masukan area bekerja : ");fflush(stdin);
							scanf ("%[^\n]",tambah.area);
							fprintf(ptr,"%d;%s;%s;%s;%s;%s;%d;%s;%d;%s;%s\n",tambah.id,tambah.nama,tambah.mitra,tambah.merk_kendaraan,tambah.type_kendaraan,tambah.transmisi,tambah.kapasitas_mesin,tambah.warna,tambah.tahun,tambah.plat,tambah.area);
							fclose(ptr);
							
							
							printf("\n\nData Mahasiswa Sudah Disimpan !");
							add_invalid:
							printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
							switch(getch()){
					    		case '1': menu();
					        		break;
					        	case '0': close();
					        		break;
					        	default:printf("\nMaaf Kesalahan Input !");
					        		getche();
					        		goto add_invalid;
					 		}	
			}
									
			void close(){		
			}
			void tampil_data()
			{
				FILE *view;
				view = fopen("datadriver.txt","r");
				int test = 0;
						system("cls");
						printf("ID\tNAMA\tMITRA\tMERK\tTYPE\tTRANSMISI\tKAPASITAS\tWARNA\tTAHUN\tPLAT\t\tAREA\n");
						while (fscanf (view, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%[^;];%d;%[^;];%[^;]\n",&tambah.id,tambah.nama,tambah.mitra,tambah.merk_kendaraan,tambah.type_kendaraan,tambah.transmisi,&tambah.kapasitas_mesin,tambah.warna,&tambah.tahun,tambah.plat,tambah.area)!=EOF)
							{
								printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n",tambah.id,tambah.nama,tambah.mitra,tambah.merk_kendaraan,tambah.type_kendaraan,tambah.transmisi,tambah.kapasitas_mesin,tambah.warna,tambah.tahun,tambah.plat,tambah.area);
								test++;
							}
							printf ("\nJumlah Data Driver : %d",test);
							fclose(view);
							
							if(test==0)
							{
								system("cls");
								printf ("\nData Kosong ! \n");
							}
							list_invalid:
						    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
						    switch(getch()){
						    	case '1': menu();
						        	break;
						        case '0': close();
						        	break;
						        default:printf("\nMaaf Kesalahan Input !");
						        	getche();
						        	goto list_invalid;
						 	}
						
			}

			
			void header(){
				time_t mytime;
				time(&mytime);
				printf("\t\t %s", ctime(&mytime));
				
			}
			
			void edit_data(){
				
			}
			
			void hapus_data(){
				
			}
			



