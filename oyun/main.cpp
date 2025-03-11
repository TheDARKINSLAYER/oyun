//2024 yazı kişisel projem
#include <iostream>
#include <string>
using namespace std;
int para1 = 0;
int para2 = 0;
int tank = 43;
int saldiran;
int savunan;
int hasar;
int savunan1;
int savunan2;
int sA1 = 1;
int sA2 = 1;
int sA3 = 1;
int sA4 = 1;
int sA5 = 1;
int sB1 = 1;
int sB2 = 1;
int sB3 = 1;
int sB4 = 1;
int sB5 = 1;
string hamle_sirasi;
string hamle;
string yerlestirme;
string birim;
string secim1;
string secim2;

int geri=1;
int tur;
int saldiri_hakki = 1;
int r=1;

int cephe[6][2]{};//cephe dizisinin tanımı


void saldiri_hakki_yenileme();
void sistem4rakipus();
void saldiri_hakki1();
void sistem3hasar();
void sistem2olum();
int hasarin();
void savas();
void saldir();
void birimler_hakkinda();
void oyun_hakkinda();
void cephe_raporu();
void birim_yerlestirme();
int para_kullanimi();
int birim_oyna2();
int birim_oyna1();




void sistem1(){
    if(hamle_sirasi =="player2")
        cout << "hamle sırası sizde player2(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/pas geç/cephe raporu/oyun hakkında):";
    
    else if(hamle_sirasi=="player1")
        cout << "hamle sırası sizde player1(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/pas geç/cephe raporu/oyun hakkında):";
}



int main(){
    cephe[5][0]=15;
    cephe[5][1]=15;
    for( tur=1;tur<31;tur++){
        if(tur%2==0){
            hamle_sirasi = "player2";
            para2++;
        }
        else{
            hamle_sirasi = "player1";
            para1++;
        }
        if(para1 == 6)
            para1--;
        if(para2 == 6)
            para2--;
        saldiri_hakki_yenileme();
        
        int c = 1;
        do{
            do{
                do{
                    do{
                        do{
                            do{
                                if(geri == 2)
                                    geri--;
                                if(c == 2)
                                    c--;
                                sistem1();
                                getline(cin,hamle);
                                if(hamle == "saldır"){
                                    saldir();
                                    if(geri==2)
                                        break;
                                    if(cephe[5][1]<1)
                                        break;
                                    if(cephe[5][0]<1)
                                        break;
                                }
                                else if(hamle == "birim oyna"){
                                    birim_oyna1();
                                    if(geri==2)
                                        break;
                                    do{
                                        if(r==2)
                                            r--;
                                        birim_oyna2();
                                    }while(r==2);
                                    if(geri==2)
                                        break;
                                    if(para_kullanimi()==2)
                                        break;
                                    birim_yerlestirme();
                                }
                                else if(hamle == "oyun hakkında")
                                    oyun_hakkinda();
                                else if(hamle == "cephe raporu")
                                    cephe_raporu();
                                else if(hamle == "pas geç")
                                    continue;
                                else{
                                    cout << "lütfen hamlenizi doğru girdiğinizden emin olun." << endl;
                                    c++;
                                }
                            }while(hamle == "saldır");
                        }while(geri == 2);
                    }while(c == 2);
                }while(hamle == "birim oyna");
            }while(hamle == "oyun hakkında");
        }while(hamle == "cephe raporu");
        if(cephe[5][1]<1)
            break;
        if(cephe[5][0]<1)
            break;
    }
    if(cephe[5][0] < cephe[5][1])
        cout << "player2 nin zaferi, tebrik ederim." << endl;
    if(cephe[5][0] > cephe[5][1])
        cout << "player1 in zaferi, tebrik ederim." << endl;
    if(cephe[5][0] == cephe[5][1]){
        if(cephe[5][0] == 15)
            cout << "TEBRİKLER İKİNİZDE KAZANDINIZ." << endl;
        else
            cout << "tebrikler ikinizde kaybettiniz." << endl;
    }
        return 0;
}

void birimler_hakkında(){
    cout << "(para bedeli)birimin adı(hasar değeri-can değeri)(özellik)" << endl;
    cout << "(1)piyade (1-1)(yok)" << endl;
    cout << "(2)mekanize piyade(2-2)(yok)" << endl;
    cout << "(3)komando(3-1)(yok)" << endl;
    cout << "(4)tank(4-3)(DAYANIKLI)" << endl << "DAYANIKLI:tüm hasar kaynaklarından -1 hasar alır." << endl;
    
    
}

void oyun_hakkinda(){
    cout << "Bu bir sıra tabanlı savaş oyunudur, 2 kişiliktir." << endl;
    cout << "tur sana geçtiğinde +1 para elde edersin, sadece pas geç komutunu kullanarak turu geçirebilirsiniz ve tur sınırı 30 dur." << endl;
    cout << "pas geçerek paranızı biriktirebilirsiniz para sınırı 5 tir." <<endl;
    cout << "birim oyna seçeneğinde biriminizi yerlestirmek istediğiniz bölgeyi ve ardından yerlestirmek istediğiniz birimi seçin, eğer paranız o birimin para bedelini karşılamıyorsa o birimi oynayamazsınız." << endl;
    birimler_hakkında();
    cout << "saldır komutu verdiğinizde kendi biriminizi seçin ve vurmak istediğiniz rakip birimi seçebilir ya da direkt olarak düşmanın ana üssüne vurabilirsiniz." << endl;
    cout << "cephe raporu komutu size savaş haritasını gösterecektir." << endl;
    cout << "ana üssün canı 0 inen taraf kaybeder, her oyuncu oyuna 15 üs canı ile başlar." << endl;
}


void cephe_raporu(){
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            
            
            if(cephe[i][j] == 11)
                cout << "             -       " << "piyade (1-1)()" << "       -             ";
            else if(cephe[i][j] == 22)
                cout << "             -   " << "mekanize piyade(2-2)()" << "   -             ";
            else if(cephe[i][j] == 21)
                cout << "             -   " << "mekanize piyade(2-1)()" << "   -             ";
            else if(cephe[i][j] == 31)
                cout << "             -       " << "komando(3-1)()" << "       -             ";
            else if(cephe[i][j] == tank)
                cout << "             -    " << "tank(4-3)(DAYANIKLI)" << "    -             ";
            else if(cephe[i][j] == tank-1)
                cout << "             -    " << "tank(4-2)(DAYANIKLI)" << "    -             ";
            else if(cephe[i][j] == tank-2)
                cout << "             -    " << "tank(4-1)(DAYANIKLI)" << "    -             ";
            else
                cout << "             -                            -             ";
            
        }
        if(i==2){
            cout << endl << "  " <<cephe[5][0] << "                                                                                                        "<< cephe[5][1] <<"  " << endl;;
        }
        else if(i==1){
            cout << endl <<"ANA ÜS"<< "                                                                                                    ANA ÜS" << endl;
        }
        else
            cout << endl << endl;
    }
}

void saldiri_hakki_yenileme(){
    if(sA1==0)
        sA1++;
    if(sA2==0)
        sA2++;
    if(sA3==0)
        sA3++;
    if(sA4==0)
        sA4++;
    if(sA5==0)
        sA5++;
    if(sB1==0)
        sB1++;
    if(sB2==0)
        sB2++;
    if(sB3==0)
        sB3++;
    if(sB4==0)
        sB4++;
    if(sB5==0)
        sB5++;
}

void sistem4rakipus(){
    if(saldiran/10 == 1)
        cout << "piyade, rakip üsse 1 hasar verdi." << endl;
    if (saldiran/10 == 2)
        cout << "mekanize piyade, rakip üsse 2 hasar verdi." << endl;
    if(saldiran/10 == 3)
        cout << "komando, rakip üsse 3 hasar verdi." << endl;
    if (saldiran/10 == 4)
        cout << "tank, rakip üsse 4 hasar verdi." << endl;
    
}


void saldiri_hakki1(){
    if(secim1=="A1"){
        if(sA1 == 1){
            sA1--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="A2"){
        if(sA2 == 1){
            sA2--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="A3"){
        if(sA3 == 1){
            sA1--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="A4"){
        if(sA4 == 1){
            sA2--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="A5"){
        if(sA5 == 1){
            sA1--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="B1"){
        if(sB1 == 1){
            sB1--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="B2"){
        if(sB2 == 1){
            sB2--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="B3"){
        if(sB3 == 1){
            sB3--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="B5"){
        if(sB4 == 1){
            sB4--;
        }else{
            saldiri_hakki--;
            
        }
        
    }
    else if(secim1=="B5"){
        if(sB5 == 1){
            sB5--;
        }else{
            saldiri_hakki--;
        }
    }
}

void sistem3hasar(){
    
    if(savunan/10==2){
        if(saldiran/10==1)
            cout << "piyade, mekanize piyadeye 1 hasar verdi." << endl;
    }
    else if(savunan/10==4){
        if(saldiran/10==1)
            cout << "piyade, tanka 0 hasar verdi." << endl;
        else if(saldiran/10==2)
            cout << "mekanize piyade, tanka 1 hasar verdi." << endl;
        else if(saldiran/10==3)
            cout << "komando, tanka 2 hasar verdi. " << endl;
        }
}


void sistem2olum(){
    if(savunan/10==1){
        if(saldiran/10==1)
            cout << "piyade, piyade tarafından yok edildi." << endl;
        else if(saldiran/10==2)
            cout << "piyade, mekanize piyade tarafından yok edildi. " << endl;
        else if(saldiran/10==3)
            cout << "piyade, komando tarafından yok edildi. " << endl;
        else if(saldiran/10==4)
            cout << "piyade, tank tarafından yok edildi. " << endl;
    }
    else if(savunan/10==2){
        if(saldiran/10==1)
            cout << "mekanize piyade, piyade tarafından yok edildi." << endl;
        else if(saldiran/10==2)
            cout << "mekanize piyade, mekanize piyade tarafından yok edildi. " << endl;
        else if(saldiran/10==3)
            cout << "mekanize piyade, komando tarafından yok edildi. " << endl;
        else if(saldiran/10==4)
            cout << "mekanize piyade, tank tarafından yok edildi. " << endl;
    }
    else if(savunan/10==3){
        if(saldiran/10==1)
            cout << "komando, piyade tarafından yok edildi." << endl;
        else if(saldiran/10==2)
            cout << "komando, mekanize piyade tarafından yok edildi. " << endl;
        else if(saldiran/10==3)
            cout << "komando, komando tarafından yok edildi. " << endl;
        else if(saldiran/10==4)
            cout << "komando, tank tarafından yok edildi. " << endl;
    }
    else if(savunan/10==4){
        if(saldiran/10==1)
            cout << "tank, piyade tarafından yok edildi." << endl;
        else if(saldiran/10==2)
            cout << "tank, mekanize piyade tarafından yok edildi. " << endl;
        else if(saldiran/10==3)
            cout << "tank, komando tarafından yok edildi. " << endl;
        else if(saldiran/10==4)
            cout << "tank, tank tarafından yok edildi. " << endl;
    }
}




int hasarin(int saldiran){
    hasar = saldiran/10;
    return hasar;
}

void savas(){
    saldiri_hakki1();
    
    
    if(saldiri_hakki==1){
        if(secim2 == "rakip üs"){
            if(hamle_sirasi == "player1")
                cephe[5][1] = cephe[5][1] - hasarin(saldiran);
            else
                cephe[5][0] = cephe[5][0] - hasarin(saldiran);
            sistem4rakipus();
        }else{
            if(cephe[savunan1][savunan2]/10 == 4)
                cephe[savunan1][savunan2] = cephe[savunan1][savunan2] - (hasarin(saldiran)-1);
            else
                cephe[savunan1][savunan2] = cephe[savunan1][savunan2] - hasarin(saldiran);
            if(cephe[savunan1][savunan2]%10 == 0){
                while(cephe[savunan1][savunan2]>0){
                    cephe[savunan1][savunan2]--;
                }
                sistem2olum();
            }
            else if(cephe[savunan1][savunan2]/10 != savunan/10){
                while(cephe[savunan1][savunan2]>0){
                    cephe[savunan1][savunan2]--;
                }
                sistem2olum();
            }else
                sistem3hasar();
        }
        
    }else{
        cout << "bu birim bu tur saldıramaz!" << endl;
        saldiri_hakki++;
        
    }
}


void saldir(){
    int c = 1;
    do{
        for(int i=1;i<2;i++){
            if(c==2)
                c--;
            if(hamle_sirasi == "player1"){
                cout << "bir dost birim seç(A1/A2/A3/A4/A5/geri):";
                getline(cin,secim1);
                
                if(secim1== "A1")
                    saldiran= cephe[0][0];
                else if(secim1 == "A2")
                    saldiran = cephe[1][0];
                else if(secim1 == "A3")
                    saldiran = cephe[2][0];
                else if(secim1 == "A4")
                    saldiran = cephe[3][0];
                else if(secim1 == "A5")
                    saldiran = cephe[4][0];
                else if(secim1 == "geri"){
                    geri++;
                    break;
                }
                else{
                    cout << "birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(saldiran == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
                cout << "herhangi bir rakip seç(B1/B2/B3/B4/B5/rakip üs/geri):";
                getline(cin,secim2);

                
                if(secim2== "B1"){
                    savunan = cephe[0][1];
                    savunan1=0;
                    savunan2=1;
                }
                else if(secim2 == "B2"){
                    savunan = cephe[1][1];
                    savunan1 = 1;
                    savunan2 = 1;
                }
                else if(secim2 == "B3"){
                    savunan = cephe[2][1];
                    savunan1 = 2;
                    savunan2 = 1;
                }
                else if(secim2 == "B4"){
                    savunan = cephe[3][1];
                    savunan1 = 3;
                    savunan2 = 1;
                }
                else if(secim2 == "B5"){
                    savunan = cephe[4][1];
                    savunan1 = 4;
                    savunan2 = 1;
                    }
                else if(secim2 == "rakip üs"){
                    savunan = cephe[5][1];
                    savunan1 = 5;
                    savunan2 = 1;
                }
                else if(secim2 == "geri"){
                    geri++;
                    break;
                }
                else{
                    cout << "birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(savunan == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
            }
            else if(hamle_sirasi == "player2"){
                cout << "bir dost birim seç(B1/B2/B3/B4/B5/geri):";
                getline(cin,secim1);
    
                if(secim1== "B1")
                    saldiran = cephe[0][1];
                else if(secim1 == "B2")
                    saldiran = cephe[1][1];
                else if(secim1 == "B3")
                    saldiran = cephe[2][1];
                else if(secim1 == "B4")
                    saldiran = cephe[3][1];
                else if(secim1 == "B5")
                    saldiran = cephe[4][1];
                else if(secim1 == "geri"){
                    geri++;
                    break;
                }
                else{
                    cout << "birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(saldiran == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
                cout << "herhangi bir rakip seç(A1/A2/A3/A4/A5/rakip üs/geri):";
                getline(cin,secim2);
                
                
                
                if(secim2== "A1"){
                    savunan = cephe[0][0];
                    savunan1 = 0;
                    savunan2 = 0;
                }
                else if(secim2 == "A2"){
                    savunan = cephe[1][0];
                    savunan1 = 1;
                    savunan2 = 0;
                }
                else if(secim2 == "A3"){
                    savunan = cephe[2][0];
                    savunan1 = 2;
                    savunan2 = 0;
                }
                else if(secim2 == "A4"){
                    savunan = cephe[3][0];
                    savunan1 = 3;
                    savunan2 = 0;
                }
                else if(secim2 == "A5"){
                    savunan = cephe[4][0];
                    savunan1 = 4;
                    savunan2 = 0;
                }
                else if(secim2 == "rakip üs"){
                    savunan = cephe[5][0];
                    savunan1 = 5;
                    savunan2 = 0;
                }
                else if(secim2 == "geri"){
                    geri++;
                    break;
                }
                else{
                    cout << "birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(savunan == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
            }
        }
    }while(c==2);
    if(geri==1)
        savas();
}

void birim_yerlestirme(){
    if(yerlestirme == "A1"){
        if(birim == "piyade")
            cephe[0][0] = 11;
        else if(birim == "mekanize piyade")
            cephe[0][0] = 22;
        else if(birim == "komando")
            cephe[0][0] = 31;
        else if(birim == "tank")
            cephe[0][0] = tank;
        sA1=1;
            }
    else if(yerlestirme == "A2"){
        if(birim == "piyade")
            cephe[1][0] = 11;
        else if(birim == "mekanize piyade")
            cephe[1][0] = 22;
        else if(birim == "komando")
            cephe[1][0] = 31;
        else if(birim == "tank")
            cephe[1][0] = tank;
        sA2=1;
        
            }
    else if(yerlestirme == "A3"){
        if(birim == "piyade")
            cephe[2][0] = 11;
        else if(birim == "mekanize piyade")
            cephe[2][0] = 22;
        else if(birim == "komando")
            cephe[2][0] = 31;
        else if(birim == "tank")
            cephe[2][0] = tank;
        sA3=1;
            }
    else if(yerlestirme == "A4"){
        if(birim == "piyade")
            cephe[3][0] = 11;
        else if(birim == "mekanize piyade")
            cephe[3][0] = 22;
        else if(birim == "komando")
            cephe[3][0] = 31;
        else if(birim == "tank")
            cephe[3][0] = tank;
        sA4=1;
            }
    else if(yerlestirme == "A5"){
        if(birim == "piyade")
            cephe[4][0] = 11;
        else if(birim == "mekanize piyade")
            cephe[4][0] = 22;
        else if(birim == "komando")
            cephe[4][0] = 31;
        else if(birim == "tank")
            cephe[4][0] = tank;
        sA5=1;
            }
    else if(yerlestirme == "B1"){
        if(birim == "piyade")
            cephe[0][1] = 11;
        else if(birim == "mekanize piyade")
            cephe[0][1] = 22;
        else if(birim == "komando")
            cephe[0][1] = 31;
        else if(birim == "tank")
            cephe[0][1] = tank;
        sB1=1;
            }
    else if(yerlestirme == "B2"){
        if(birim == "piyade")
            cephe[1][1] = 11;
        else if(birim == "mekanize piyade")
            cephe[1][1] = 22;
        else if(birim == "komando")
            cephe[1][1] = 31;
        else if(birim == "tank")
            cephe[1][1] = tank;
        sB2=1;
            }
    else if(yerlestirme == "B3"){
        if(birim == "piyade")
            cephe[2][1] = 11;
        else if(birim == "mekanize piyade")
            cephe[2][1] = 22;
        else if(birim == "komando")
            cephe[2][1] = 31;
        else if(birim == "tank")
            cephe[2][1] = tank;
        sB3=1;
            }
    else if(yerlestirme == "B4"){
        if(birim == "piyade")
            cephe[3][1] = 11;
        else if(birim == "mekanize piyade")
            cephe[3][1] = 22;
        else if(birim == "komando")
            cephe[3][1] = 31;
        else if(birim == "tank")
            cephe[3][1] = tank;
        sB4=1;
            }
    else if(yerlestirme == "B5"){
        if(birim == "piyade")
            cephe[4][1] = 11;
        else if(birim == "mekanize piyade")
            cephe[4][1] = 22;
        else if(birim == "komando")
            cephe[4][1] = 31;
        else if(birim == "tank")
            cephe[4][1] = tank;
        sB5=1;
            }
}

int para_kullanimi(){
    if(hamle_sirasi == "player1"){
        if(para1>3){
            if(birim =="tank")
                para1-=4;
            else if(birim == "komando")
                para1-=3;
            else if (birim == "mekanize piyade")
                para1-=2;
            else if(birim == "piyade")
                para1--;
        }else if(para1==3){
            if(birim == "piyade")
                para1--;
            else if(birim == "mekanize piyade")
                para1-=2;
            else if(birim == "komando")
                para1-=3;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
            }
        }else if(para1==2){
            if(birim == "piyade")
                para1--;
            else if(birim == "mekanize piyade")
                para1-=2;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
                
            }
        }else if(para1==1){
            if(birim == "piyade")
                para1--;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
            }
        }else if(para1 == 0){
            cout << "paranız yeterli değil!" << endl;
            geri++;
        }
    }
    else if(hamle_sirasi == "player2"){
        if(para2>3){
            if(birim =="tank")
                para2-=4;
            else if(birim == "komando")
                para2-=3;
            else if (birim == "mekanize piyade")
                para2-=2;
            else if(birim == "piyade")
                para2--;
        }else if(para2==3){
            if(birim == "piyade")
                para2--;
            else if(birim == "mekanize piyade")
                para2-=2;
            else if(birim == "komando")
                para2-=3;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
            }
        }else if(para2==2){
            if(birim == "piyade")
                para2--;
            else if(birim == "mekanize piyade")
                para2-=2;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
                
            }
        }else if(para2==1){
            if(birim == "piyade")
                para2--;
            else{
                cout << "paranız yeterli değil!" << endl;
                geri++;
            }
        }else if(para2 == 0){
            cout << "paranız yeterli değil!" << endl;
            geri++;
        }
    }
    return geri;
}

int birim_oyna2(){
    string b;
    int c=1;
    do{
        if(c==2)
            c--;
            cout << yerlestirme << " konumuna yerlestirmek istediğiniz birimi seçin(piyade/mekanize piyade/komando/tank/birimler hakkında/geri):";
            getline(cin,b);
            if(b == "piyade")
                birim = b;
            else if(b == "mekanize piyade")
                birim = b;
            else if(b == "komando")
                birim = b;
            else if(b == "tank")
                birim = b;
            else if(b == "birimler hakkında"){
                birimler_hakkında();
                c++;
            }
            else if (b == "geri"){
                geri++;
                break;
                
            }else{
                cout << "yerlestirmek istediğiniz biriminin adını doğru yazınız!" << endl;
                c++;
            }
    }while(c==2);
    return geri;
}

int birim_oyna1(){
    string a;
    int c=1;
    do{
        if(hamle_sirasi == "player1"){
            
            if(c==2)
                c--;
            cout << "yerleştirilecek bölgeyi seçin(A1/A2/A3/A4/A5/geri):";
            getline(cin,a);
            if(a == "A1")
                yerlestirme = a;
            else if(a == "A2")
                yerlestirme = a;
            else if(a == "A3")
                yerlestirme = a;
            else if(a == "A4")
                yerlestirme = a;
            else if(a == "A5")
                yerlestirme = a;
            else if(a=="geri"){
                geri++;
                break;
            }else{
                cout << "yerleştirilecek bölgeyi doğru tanımlayın!" << endl;
                c++;
            }
            
        }
        else if(hamle_sirasi == "player2"){
            
            if(c==2)
                c--;
            cout << "yerleştirilecek bölgeyi seçin(B1/B2/B3/B4/B5/geri):";
            getline(cin,a);
            if(a == "B1")
                yerlestirme = a;
            else if(a == "B2")
                yerlestirme = a;
            else if(a == "B3")
                yerlestirme = a;
            else if(a == "B4")
                yerlestirme = a;
            else if(a == "B5")
                yerlestirme = a;
            else if(a=="geri"){
                geri++;
                break;
            }else{
                cout << "yerleştirilecek bölgeyi doğru tanımlayın!" << endl;
                c++;
            }
            
        }
    }while(c==2);
    return geri;
}

