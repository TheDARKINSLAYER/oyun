//2024 yazı kişisel projem
#include <iostream>
#include <string>
using namespace std;
int para1 = 0;
int para2 = 0;
long saldiran;
long savunan;
long hasar;
int savunan1;
int savunan2;
int saldiran1;
int saldiran2;
int sA1 = 0;
int sA2 = 0;
int sA3 = 0;
int sA4 = 0;
int sA5 = 0;
int sB1 = 0;
int sB2 = 0;
int sB3 = 0;
int sB4 = 0;
int sB5 = 0;
int anaus1 = 1;
int anaus2 = 1;
int havalimani1 = 0;
int havalimani2 = 0;
long piyade1   = 11111000000000;   //birimlerin değeri:birim no,hasar,can,bedel,menzil,kamuflaj(x2),dayanıklı,mobilize,çifte saldırı(x2),mayın,aşırı güç,önleme
long piyade2   = 11111000000000;
long mekanize1 = 22221000000000;
long mekanize2 = 22221000000000;
long komando1  = 33133000000000;
long komando2  = 33133000000000;
long tank1     = 44341001000000;
long tank2     = 44341001000000;
string hamle_sirasi;
string hamle;
string yerlestirme;
string birim;
string secim1;
string secim2;
int doktrin1 = 0;
int doktrin2 = 0;
int geliştirmeler1 = 0;
int geliştirmeler2 = 0;

int askereal = 0;

int geri=1;
int tur;
int saldiri_hakki = 1;

long cephe[6][2]{};//cephe dizisinin tanımı
int a=3;            //havalimanlarının kapasitesi
int b=3;



void saldiri_hakki_yenileme();
void sistem4rakipus();
void saldiri_hakki1();
void sistem3hasar();
void sistem2olum();
void ciftesaldiri();
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


void savunmasanayi(){
    int c = 1;
    do{
        if(c==2)
            c--;
        string secim;
        cout << "as askere eklemek istediğiniz teçhizatı seçiniz(gelişmiş dürbün/kamuflaj/mayın/geri)";
        getline(cin,secim);
        if(hamle_sirasi == "player1"){
            if(secim == "gelişmiş dürbün")
                komando1 = komando1 + 2e+10;
            else if(secim == "kamuflaj")
                komando2 = komando1 + 11e+7;
            else if(secim == "mayın")
                komando1 = komando1 + 100;
            else if(secim == "geri"){
                geri++;
            }
            else{
                cout << "teçhizat adını doğru girdiğinizden emin olun!" << endl;
                c++;
            }
        }else{
            if(secim == "gelişmiş dürbün")
                komando2 = komando2 + 2e+10;
            else if(secim == "kamuflaj")
                komando2 = komando2 + 11e+7;
            else if(secim == "mayın")
                komando2 = komando2 + 100;
            else if(secim == "geri"){
                geri++;
            }
            else{
                cout << "teçhizat adını doğru girdiğinizden emin olun!" << endl;
                c++;
            }

        }
    }while(c == 2);
}




void modernizasyon(){
    if(hamle_sirasi == "player1"){
        for(int i = 0;i<5;i++){
            
            if(cephe[i][0]/1e+13 == 1){  //piyadeyse
                cephe[i][0] = piyade1;
            }
            else if(cephe[i][0]/1e+13 == 2){  //mekanize piyadeyse
                cephe[i][0] = mekanize1;
                
            }
            else if(cephe[i][0]/1e+13 == 3){  //komandoysa
                cephe[i][0] = komando1;
                
            }
            else if(cephe[i][0]/1e+13 == 4){  //tanksa
                cephe[i][0] = tank1;
                
            }
            
        }
    }else{
        for(int i = 0;i<5;i++){
            if(cephe[i][1]/1e+13 == 1){  //piyadeyse
                cephe[i][1] = piyade2;
            }
            else if(cephe[i][1]/1e+13 == 2){  //mekanize piyadeyse
                cephe[i][1] = mekanize2;
                
            }
            else if(cephe[i][1]/1e+13 == 3){  //komandoysa
                cephe[i][1] = komando2;
                
            }
            else if(cephe[i][1]/1e+13 == 4){  //tanksa
                cephe[i][1] = tank2;
                
            }
        }
    }
}

void doktrinler(){
    if(hamle_sirasi == "player1"){
        if(doktrin1 == 1){
            piyade1 = piyade1+1e+12;
        }
        else if(doktrin1 == 2){
            tank1 = tank1 - 1e+12;
            tank1 = tank1 - 1e11;
            tank1 = tank1 - 1e+10;
            mekanize1 = mekanize1 - 1e+12;
            komando1 = komando1 - 1e+10;
        }
        else if(doktrin1 == 3){
            komando1 = komando1 - 1e+12;
            komando1 = komando1 - 1e+10;
        }
        else if(doktrin1 == 4){
            mekanize1 = mekanize1 + 1e11;
            mekanize1 = mekanize1 + 1e+6;
            mekanize1 = mekanize1 + 1;
            tank1 = tank1 - 1e+12;
            tank1 = tank1 - 1e11;
            tank1 = tank1 - 1e+10;
            tank1 = tank1 + 1e+6;
            tank1 = tank1 + 11000;
            
        }
    }else{
        if(doktrin1 == 1){
            piyade1 = piyade1+1e+12;
        }
        else if(doktrin1 == 2){
            tank1 = tank1 - 1e+12;
            tank1 = tank1 - 1e11;
            tank1 = tank1 - 1e+10;
            mekanize1 = mekanize1 - 1e+12;
            komando1 = komando1 - 1e+10;
        }
        else if(doktrin1 == 3){
            komando1 = komando1 - 1e+12;
            komando1 = komando1 - 1e+10;
        }
        else if(doktrin1 == 4){
            mekanize1 = mekanize1 + 1e11;
            mekanize1 = mekanize1 + 1e+6;
            mekanize1 = mekanize1 + 1;
            tank1 = tank1 - 1e+12;
            tank1 = tank1 - 1e11;
            tank1 = tank1 - 1e+10;
            tank1 = tank1 + 1e+6;
            tank1 = tank1 + 11000;
            
        }
    }
}

void doktrinlerhakkında(){
    
}

void gelistirmelerbilgi(){
    cout << "geliştirmeleri tamamlayarak daha fazla para kazanabilir bu paraları daha iyi depolayabilirsiniz,3. geliştirme savaş doktrini seçimidir doktrinler sayesinde paranın nasıl yönetileceği daha iyi kararlaştırılabileneceğinden para verimi artacaktır veya havalimanını geliştirerek hava gücünden yararlanabilirsiniz." << endl;
    cout << "/1. ana üs geliştirmesi/maaliyet= 3/tur başına geliri 2 yapar." << endl;
    cout << "/2. ana üs geliştirmesi/maaliyet= 5/para kapasitesini 7 yapar." << endl;
    cout << "/3. ana üs geliştirmesi yani doktrin seçimi/maaliyet= 0/tur başı para kazanımını 3 yapar." << endl;
    cout << "doktrin seçen player modernizasyon etkisi kazanır.";
    cout << "modernizasyon doktrin seçildiği anda sahada bulunan dost birim sayısı kadar tur -1 gelir elde etmenizi sağlayan bir debufftır." << endl;
}

void gelistirme(){
    string a;
    string b;
    int c = 1;
    do{
        if(c == 2)
            c--;
        if(hamle_sirasi == "player1"){
            if(geliştirmeler1 == 1){
                cout << "geliştirmeleri tamamladınız player1." << endl;
                break;
            }
            if(anaus1 == 1){
                cout << "geliştirilecek herhangi bir şey seçin player1(ana üs/geliştirmeler hakkında/geri):";
                getline(cin,a);
                if(a == "ana üs"){
                    if(para1>2){
                        anaus1++;
                        para1-=3;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if(a == "geliştirmeler hakkında"){
                    gelistirmelerbilgi();
                    c++;
                }
                else if(a == "geri")
                    geri++;
                else{
                    cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                    c++;
                }
            }
            else if(anaus1 == 2){
                cout << "geliştirilecek herhangi bir şey seçin player1(ana üs/havalimanı/geliştirmeler hakkında):";
                getline(cin,a);
                
                if(a == "ana üs"){
                    if(para1>4){
                        anaus1++;
                        para1-=5;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if (a == "havalimanı"){
                    if(para1>2){
                        havalimani1++;
                        para1-=3;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if(a == "geliştirmeler hakkında"){
                    gelistirmelerbilgi();
                    c++;
                }
                else if(a == "geri")
                    geri++;
                else{
                    cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                    c++;
                }
            }
            else if(anaus1 > 2){
                if(doktrin1 == 0){
                    if(havalimani1 == 1){
                        cout << "geliştirilecek herhangi bir şey seçin player1(savaş doktrini/geliştirmeler hakkında/geri):";
                        getline(cin,a);
                        if(a == "savaş doktrini"){
                            cout << "yeni savaş doktrinizi seçiniz, uyarı bir daha değiştirilemez(blitzkreig/superfirepower/deep war/special forces/doktrinler hakkında/geri):";
                            getline(cin,b);
                            if(b == "blitzkreig"){
                                doktrin1+=4;
                                anaus1++;
                                geliştirmeler1++;
                            }
                            else if(b == "superfirepower"){
                                doktrin1+= 2;
                                anaus1++;
                                geliştirmeler1++;
                            }
                            else if(b == "deep war"){
                                doktrin1+= 1;
                                anaus1++;
                                geliştirmeler1++;
                            }
                            else if(b == "special forces"){
                                doktrin1+= 3;
                                anaus1++;
                                geliştirmeler1++;
                            }
                            else if(a == "doktrinler hakkında"){
                                doktrinlerhakkında();
                                c++;
                            }
                            else if(b == "geri")
                                geri++;
                            else{
                                cout << "doktrinin adını doğru yazdığınızdan emin olun!" << endl;
                                c++;
                            }
                        }
                        
                        
                    }else if(havalimani1 == 0){
                        cout << "geliştirilecek herhangi bir şey seçin player1(savaş doktrini/havalimanı/geliştirmeler hakkında/geri):";
                        getline(cin,a);
                        if(a == "savaş doktrini"){
                            cout << "yeni savaş doktrinizi seçiniz, uyarı bir daha değiştirilemez(blitzkreig/superfirepower/deep war/special forces/geri):";
                            getline(cin,b);
                            if(b == "blitzkreig"){
                                doktrin1+=4;
                                anaus1++;
                            }
                            else if(b == "superfirepower"){
                                doktrin1+= 2;
                                anaus1++;
                            }
                            else if(b == "deep war"){
                                doktrin1+= 1;
                                anaus1++;
                            }
                            else if(b == "special forces"){
                                doktrin1+= 4;
                                anaus1++;
                            }
                            else if(a == "doktrinler hakkında"){
                                doktrinlerhakkında();
                                c++;
                            }
                            else if(b == "geri")
                                geri++;
                            else{
                                cout << "doktrinin adını doğru yazdığınızdan emin olun!" << endl;
                                c++;
                            }
                        }
                        else if (a == "havalimanı"){
                            if(para1>2){
                                havalimani1++;
                                para1-=3;
                            }else{
                                cout << "paranız yeterli değil!" << endl;
                                geri++;
                            }
                        }
                        else if(a == "geliştirmeler hakkında"){
                            gelistirmelerbilgi();
                            c++;
                        }
                        else if(a == "geri")
                            geri++;
                        else{
                            cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                            c++;
                        }
                    }
                }else{
                    cout << "geliştirilecek herhangi bir şey seçin player1(havalimanı/geliştirmeler hakkında/geri):";
                    getline(cin,a);
                    if(a == "havalimanı"){
                        if(para1>2){
                            havalimani1++;
                            para1-=3;
                            geliştirmeler1++;
                        }else{
                            cout << "paranız yeterli değil!" << endl;
                            geri++;
                        }
                        
                    }
                    else if(a == "geliştirmeler hakkında"){
                        gelistirmelerbilgi();
                        c++;
                    }
                    else if(a == "geri")
                        geri++;
                    else{
                        cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                        c++;
                    }
                }
            }
        }
        else if(hamle_sirasi == "player2"){
            if(geliştirmeler2 == 1){
                cout << "geliştirmeleri tamamladınız player2." << endl;
                break;
            }
            if(anaus2 == 1){
                cout << "geliştirilecek herhangi bir şey seçin player2(ana üs/geliştirmeler hakkında/geri):";
                getline(cin,a);
                if(a == "ana üs"){
                    if(para2>2){
                        anaus2++;
                        para2-=3;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if(a == "geliştirmeler hakkında"){
                    gelistirmelerbilgi();
                    c++;
                }
                else if(a == "geri")
                    geri++;
                else{
                    cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                    c++;
                }
            }
            else if(anaus2 == 2){
                cout << "geliştirilecek herhangi bir şey seçin player2(ana üs/havalimanı/geliştirmeler hakkında):";
                getline(cin,a);
                
                if(a == "ana üs"){
                    if(para2>4){
                        anaus2++;
                        para2-=5;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if (a == "havalimanı"){
                    if(para2>2){
                        havalimani2++;
                        para2-=3;
                    }else{
                        cout << "paranız yeterli değil!" << endl;
                        geri++;
                    }
                }
                else if(a == "geliştirmeler hakkında"){
                    gelistirmelerbilgi();
                    c++;
                }
                else if(a == "geri")
                    geri++;
                else{
                    cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                    c++;
                }
            }
            else if(anaus2 > 2){
                if(doktrin2 == 0){
                    if(havalimani2 == 1){
                        cout << "geliştirilecek herhangi bir şey seçin player2(savaş doktrini/geliştirmeler hakkında/geri):";
                        getline(cin,a);
                        if(a == "savaş doktrini"){
                            cout << "yeni savaş doktrinizi seçiniz, uyarı bir daha değiştirilemez(blitzkreig/superfirepower/deep war/special forces/doktrinler hakkında/geri):";
                            getline(cin,b);
                            if(b == "blitzkreig"){
                                doktrin2=4;
                                anaus2++;
                                geliştirmeler2++;
                            }
                            else if(b == "superfirepower"){
                                doktrin2+= 2;
                                anaus2++;
                                geliştirmeler2++;
                            }
                            else if(b == "deep war"){
                                doktrin2+= 1;
                                anaus2++;
                                geliştirmeler2++;
                            }
                            else if(b == "special forces"){
                                doktrin2+= 3;
                                anaus2++;
                                geliştirmeler2++;
                            }
                            else if(a == "doktrinler hakkında"){
                                doktrinlerhakkında();
                                c++;
                            }
                            else if(b == "geri")
                                geri++;
                            else{
                                cout << "doktrinin adını doğru yazdığınızdan emin olun!" << endl;
                                c++;
                            }
                        }
                        
                        
                    }else if(havalimani2 == 0){
                        cout << "geliştirilecek herhangi bir şey seçin player2(savaş doktrini/havalimanı/geliştirmeler hakkında/geri):";
                        getline(cin,a);
                        if(a == "savaş doktrini"){
                            cout << "yeni savaş doktrinizi seçiniz, uyarı bir daha değiştirilemez(blitzkreig/superfirepower/deep war/special forces/geri):";
                            getline(cin,b);
                            if(b == "blitzkreig"){
                                doktrin2++;
                                anaus2++;
                            }
                            else if(b == "superfirepower"){
                                doktrin2+= 2;
                                anaus2++;
                            }
                            else if(b == "deep war"){
                                doktrin2+= 3;
                                anaus2++;
                            }
                            else if(b == "special forces "){
                                doktrin2+= 4;
                                anaus2++;
                            }
                            else if(a == "doktrinler hakkında"){
                                doktrinlerhakkında();
                                c++;
                            }
                            else if(b == "geri")
                                geri++;
                            else{
                                cout << "doktrinin adını doğru yazdığınızdan emin olun!" << endl;
                                c++;
                            }
                        }
                        else if (a == "havalimanı"){
                            if(para2>2){
                                havalimani2++;
                                para2-=3;
                            }else{
                                cout << "paranız yeterli değil!" << endl;
                                geri++;
                            }
                        }
                        
                        else if(a == "geliştirmeler hakkında"){
                            gelistirmelerbilgi();
                            c++;
                        }
                        else if(a == "geri")
                            geri++;
                        else{
                            cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                            c++;
                        }
                    }
                }else{
                    cout << "geliştirilecek herhangi bir şey seçin player2(havalimanı/geliştirmeler hakkında/geri):";
                    getline(cin,a);
                    if(a == "havalimanı"){
                        if(para2>2){
                            havalimani2++;
                            para2-=3;
                            geliştirmeler2++;
                        }else{
                            cout << "paranız yeterli değil!" << endl;
                            geri++;
                        }
                        
                    }
                    else if(a == "geliştirmeler hakkında"){
                        gelistirmelerbilgi();
                        c++;
                    }
                    else if(a == "geri")
                        geri++;
                    else{
                        cout << "geliştirmenin ismini doğru yazdığınızdan emin olun!" << endl;
                        c++;
                        
                        
                    }
                }
            }
        }
    }while(c == 2);
}




void sistem1(){
    if(hamle_sirasi =="player2"){
        if(doktrin2 == 1){
            if(havalimani2 == 1){
                cout << "hamle sırası sizde player2(" << askereal <<")(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/havalimanı/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player2(" << askereal <<")(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }
        else if(doktrin2 == 3){
            if(havalimani2 == 1){
                cout << "hamle sırası sizde player2(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/havalimanı/savunma sanayi/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player2(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/savunma sanayi/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }else{
            if(havalimani2 == 1){
                cout << "hamle sırası sizde player2(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/havalimanı/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player2(tur sayacı:" << tur <<")(para:"<< para2 << ")(saldır/birim oyna/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }
    }else{
        if(doktrin1 == 1){
            if(havalimani1 == 1){
                cout << "hamle sırası sizde player1(" << askereal <<")(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/havalimanı/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player1(" << askereal <<")(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }
        else if(doktrin1 == 3){
            if(havalimani1 == 1){
                cout << "hamle sırası sizde player1(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/havalimanı/savunma sanayi/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player1(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/savunma sanayi/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }else{
            if(havalimani1 == 1){
                cout << "hamle sırası sizde player1(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/havalimanı/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }else{
                cout << "hamle sırası sizde player1(tur sayacı:" << tur <<")(para:"<< para1 << ")(saldır/birim oyna/geliştirme/pas geç/cephe raporu/oyun hakkında):";
            }
        }
    }
}

int donusturucu1(int a){
    return a;
}

int donusturucu2(int a , int b){
    int sonuc =  a-b*10;
    return sonuc;
}




int main(){
    cephe[5][0]=15;      //ana üslerin canlarının tanımlandığı yer
    cephe[5][1]=15;
    for(tur=1;tur<31;tur++){
        if(tur%2==0){
            hamle_sirasi = "player2";      //para kazanma player2
            if(anaus2 == 1){
                para2++;
            }
            else if(anaus2 == 2){
                para2+=2;
            }
            else if(anaus2 == 3){
                para2+=2;
            }
            else if(anaus2 == 4){
                para2+=3;
            }
            if(anaus2>2){
                while(para2 > 7)
                    para2--;
            }else{
                while(para2 > 5)
                    para2--;
            }
        }else{
            hamle_sirasi = "player1";        //para kazanma player1
            if(anaus1 == 1){
                para1++;
            }
            else if(anaus1 == 2){
                para1+=2;
            }
            else if(anaus1 == 3){
                para1+=2;
            }
            else if(anaus1 == 4){
                para1+=3;
            }
            if(anaus1>2){
                while(para1 > 7)
                    para1--;
            }else{
                while(para1 > 5)
                    para1--;
            }
        }
        saldiri_hakki_yenileme();
        while(askereal > 0){                                       //seferberlik sıfırlanması
            askereal--;
        }
        for(int i=0;i<5;i++){                                      //çifte saldırı yenilenmesi
            for(int j=0;j<2;j++){
                if(cephe[i][j]/1e+4-cephe[i][j]/1e+6*100 == 10){
                    cephe[i][j]+=10000;
                }
            }
        }
        int c = 1;
        do{
            do{
                do{
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
                                                birim_oyna2();
                                                
                                                if(geri==2)
                                                    break;
                                                if(para_kullanimi()==2)
                                                    break;
                                                birim_yerlestirme();
                                            }
                                            else if(hamle == "havalimanı"){
                                                if(hamle_sirasi== "player1"){
                                                    if(havalimani1 == 0){
                                                        cout << "havalimanınızı geliştirin." << endl;
                                                        c++;
                                                        break;
                                                    }else{
                                                        
                                                    }
                                                }else{
                                                    if(havalimani2 == 0){
                                                        cout << "havalimanınızı geliştirin." << endl;
                                                        c++;
                                                        break;
                                                    }
                                                }
                                            }
                                            else if(hamle == "savunma sanayi"){
                                                if(hamle_sirasi== "player1"){
                                                    if(doktrin1 != 3){
                                                        cout << "lütfen hamlenizi doğru girdiğinizden emin olun.";
                                                    }else{
                                                        savunmasanayi();
                                                        if(geri == 2)
                                                            break;
                                                    }
                                                }else{
                                                    if(doktrin2 != 3){
                                                        cout << "lütfen hamlenizi doğru girdiğinizden emin olun.";
                                                    }else{
                                                        savunmasanayi();
                                                        if(geri == 2)
                                                            break;
                                                    }
                                                }
                                            }
                                            else if(hamle == "geliştirme"){
                                                gelistirme();
                                                if(geri == 2)
                                                    break;
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
                        }while(hamle == "havalimanı");
                    }while(hamle == "savunma sanayi");
                }while(hamle == "geliştirme");
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
            cout << "beraberlik." << endl;
        return 0;
    }
}

void birimler_hakkında(){
    cout << "(para bedeli)birimin adı(hasar değeri-can değeri)(özellik)" << endl;
    cout << "(1)piyade (1-1)(yok)" << endl;
    cout << "(2)mekanize piyade(2-2)(yok)" << endl;
    cout << "(3)komando(3-1)(yok)" << endl;
    cout << "(4)tank(4-3)(DAYANIKLI)" << endl << "DAYANIKLI:tüm hasar kaynaklarından 1 az hasar alır." << endl;
    
    
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
            if(j == 0){
                if(donusturucu1(cephe[i][j]/1e+13) == 1){
                    if(doktrin1 == 1){
                        cout << "             ";
                        cout << "-       yoldaş (" << donusturucu1(cephe[i][j]/1e+12)-10 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")         -             ";
                    }else{
                        cout << "             ";
                        cout << "-        piyade (" << donusturucu1(cephe[i][j]/1e+12)-10 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")        -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 2){
                    if(doktrin1 == 4){
                        cout << "             ";
                        cout << "-     Sd. Kfz. 251 (" << donusturucu1(cephe[i][j]/1e+12)-20 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")     -             ";
                    }else{
                        cout << "             ";
                        cout << "-    mekanize piyade(" << donusturucu1(cephe[i][j]/1e+12)-20 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")    -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 3){
                    if(doktrin1 == 3){
                        cout << "             ";
                        cout << "-      as asker(" << donusturucu1(cephe[i][j]/1e+12)-30 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")       -             ";
                    }else{
                        cout << "             ";
                        cout << "-        komando(" << donusturucu1(cephe[i][j]/1e+12)-30 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")        -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 4){
                    if(doktrin1 == 4){
                        cout << "             ";
                        cout << "-     panther(" << donusturucu1(cephe[i][j]/1e+12)-40 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")       -             ";
                    }else{
                        cout << "             ";
                        cout << "-         tank (" << donusturucu1(cephe[i][j]/1e+12)-40 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")         -             ";
                    }
                }
                else
                    cout << "             -                            -             ";
                
            }else{
                if(donusturucu1(cephe[i][j]/1e+13) == 1){
                    if(doktrin2 == 1){
                        cout << "             ";
                        cout << "-       yoldaş (" << donusturucu1(cephe[i][j]/1e+12)-10 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")       -             ";
                    }else{
                        cout << "             ";
                        cout << "-        piyade (" << donusturucu1(cephe[i][j]/1e+12)-10 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")        -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 2){
                    if(doktrin1 == 4){
                        cout << "             ";
                        cout << "-     Sd. Kfz. 251 (" << donusturucu1(cephe[i][j]/1e+12)-30 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")     -             ";
                    }else{
                        cout << "             ";
                        cout << "-    mekanize piyade(" << donusturucu1(cephe[i][j]/1e+12)-20 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")    -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 3){
                    if(doktrin2 == 3){
                        cout << "             ";
                        cout << "-      as asker(" << donusturucu1(cephe[i][j]/1e+12)-30 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")       -             ";
                    }else{
                        cout << "             ";
                        cout << "-        komando(" << donusturucu1(cephe[i][j]/1e+12)-30 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")        -             ";
                    }
                }
                else if(donusturucu1(cephe[i][j]/1e+13) == 4){
                    if(doktrin2 == 4){
                        cout << "             ";
                        cout << "-       panther(" << donusturucu1(cephe[i][j]/1e+12)-40 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")       -             ";
                    }else{
                        cout << "             ";
                        cout << "-         tank (" << donusturucu1(cephe[i][j]/1e+12)-40 << "-" << donusturucu2(cephe[i][j]/1e11,cephe[i][j]/1e+12) << ")         -             ";
                    }
                }else
                    cout << "             -                            -             ";
                
            }
            
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
    if(hamle_sirasi == "playee1"){
        if(saldiran/1e+13 == 1){
            if(doktrin1 != 1){
                cout << "piyade, rakip üsse " << (saldiran/1e+12-10) << " hasar verdi." << endl;
            }
            else if(doktrin1 == 1){
                cout << "yoldaş, rakip üsse " << (saldiran/1e+12-10) << " hasar verdi." << endl;
            }
        }
        else if (saldiran/1e+13 == 2){
            if(doktrin1 != 4){
                cout << "mekanize piyade, rakip üsse " << (saldiran/1e+12-20) << " hasar verdi." << endl;
            }
            else if(doktrin1 == 4){
                cout << "Sd. Kfz. 251, rakip üsse "<< (saldiran/1e+12-20) << " hasar verdi." << endl;
            }
        }
        else if(saldiran/1e+13 == 3){
            if(doktrin1 != 3){
                cout << "komando, rakip üsse " << (saldiran/1e+12-30) << " hasar verdi." << endl;
            }
            else if(doktrin1 == 3){
                cout << "as asker, rakip üsse " << (saldiran/1e+12-30) << " hasar verdi." << endl;
            }
        }
        else if (saldiran/1e+13 == 4){
            if(doktrin1 != 4){
                cout << "tank, rakip üsse " << (saldiran/1e+12-40) << " hasar verdi." << endl;
            }
            else if(doktrin1 == 4){
                cout << "panther, rakip üsse " << (saldiran/1e+12-40) << " hasar verdi." << endl;
            }
        }
    }else{
        if(saldiran/1e+13 == 1){
            if(doktrin2 != 1){
                cout << "piyade, rakip üsse " << (saldiran/1e+12-10) << " hasar verdi." << endl;
            }
            else if(doktrin2 == 1){
                cout << "yoldaş, rakip üsse " << (saldiran/1e+12-10) << " hasar verdi." << endl;
            }
        }
        else if (saldiran/1e+13 == 2){
            if(doktrin2 != 4){
                cout << "mekanize piyade, rakip üsse " << (saldiran/1e+12-20) << " hasar verdi." << endl;
            }
            else if(doktrin2 == 4){
                cout << "Sd. Kfz. 251, rakip üsse "<< (saldiran/1e+12-20) << " hasar verdi." << endl;
            }
        }
        else if(saldiran/1e+13 == 3){
            if(doktrin2 != 3){
                cout << "komando, rakip üsse " << (saldiran/1e+12-30) << " hasar verdi." << endl;
            }
            else if(doktrin2 == 3){
                cout << "as asker, rakip üsse " << (saldiran/1e+12-30) << " hasar verdi." << endl;
            }
        }
        else if (saldiran/1e+13 == 4){
            if(doktrin2 != 4){
                cout << "tank, rakip üsse " << (saldiran/1e+12-40) << " hasar verdi." << endl;
            }
            else if(doktrin2 == 4){
                cout << "panther, rakip üsse " << (saldiran/1e+12-40) << " hasar verdi." << endl;
            }
        }
    }

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
    if(hamle_sirasi == "player1"){
        if(savunan/1e+13==1){
            if(saldiran/1e+13==1){
                if(doktrin1 == 1){
                    if(doktrin2 == 1)
                        cout << "yoldaş, yoldaşa " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "yoldaş, piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 1)
                        cout << "piyade, yoldaşa " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "piyade, piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==2){
                if(doktrin1 == 4){
                    if(doktrin2 == 1)
                        cout << "Sd, Kfz. 251, yoldaşa " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "Sd, Kfz. 251, piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 1)
                        cout << "mekanize piyade, yoldaşa " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "mekanize piyade, piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==3){
                if(doktrin1 == 3){
                    if(doktrin2 == 1)
                        cout << "as asker, yoldaşa " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "as asker, piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 1)
                        cout << "komando, yoldaşa " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "komando, piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==4){
                if(doktrin1 == 4){
                    if(doktrin2 == 1)
                        cout << "panther, yoldaşa " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "panther, piyadeye " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 1)
                        cout << "tank, yoldaşa " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "tank, piyadeya " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    
                }
            }

        }
        else if(savunan/1e+13==2){
            if(saldiran/1e+13==1){
                if(doktrin1 == 1){
                    if(doktrin2 == 4)
                        cout << "yoldaş, Sd, Kfz. 251'e " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "yoldaş, mekanize piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "piyade, Sd, Kfz. 251'e " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "piyade, mekanize piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==2){
                if(doktrin1 == 4){
                    if(doktrin2 == 4)
                        cout << "Sd, Kfz. 251, Sd, Kfz. 251'e " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "Sd, Kfz. 251, mekanize piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "mekanize piyade, Sd, Kfz. 251'e " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "mekanize piyade, mekanize piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==3){
                if(doktrin1 == 3){
                    if(doktrin2 == 4)
                        cout << "as asker, Sd, Kfz. 251'e " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "as asker, mekanize piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "komando, Sd, Kfz. 251'e " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "komando, mekanize piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==4){
                if(doktrin1 == 4){
                    if(doktrin2 == 4)
                        cout << "panther, Sd, Kfz. 251'e " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "panther, mekanize piyadeye " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "tank, Sd, Kfz. 251'e " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "tank, mekanize piyadeye " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    
                }
            }

        }
        else if(savunan/1e+13==3){
            if(saldiran/1e+13==1){
                if(doktrin1 == 1){
                    if(doktrin2 == 3)
                        cout << "yoldaş, as askere " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "yoldaş, komandoya " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 3)
                        cout << "piyade, as askere " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "piyade, komandoya " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==2){
                if(doktrin1 == 4){
                    if(doktrin2 == 3)
                        cout << "Sd, Kfz. 251, as askere " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "Sd, Kfz. 251, komandoya " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 3)
                        cout << "mekanize piyade, as askere " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "mekanize piyade, komandoya " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==3){
                if(doktrin1 == 3){
                    if(doktrin2 == 3)
                        cout << "as asker, as askere " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "as asker, komandoya " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 3)
                        cout << "komando, as askere " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "komando, komandoya " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==4){
                if(doktrin1 == 4){
                    if(doktrin2 == 3)
                        cout << "panther, as askere " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "panther, komandoya " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 3)
                        cout << "tank, as askere " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "tank, komandoya " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    
                }
            }

        }
        else if(savunan/1e+13==4){
            if(saldiran/1e+13==1){
                if(doktrin1 == 1){
                    if(doktrin2 == 4)
                        cout << "yoldaş, panthere " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "yoldaş, piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "piyade, yoldaşa " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    else
                        cout << "piyade, piyadeye " << (saldiran/1e+12-10) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==2){
                if(doktrin1 == 4){
                    if(doktrin2 == 4)
                        cout << "Sd, Kfz. 251, yoldaşa " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "Sd, Kfz. 251, piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "mekanize piyade, yoldaşa " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    else
                        cout << "mekanize piyade, piyadeye " << (saldiran/1e+12-20) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==3){
                if(doktrin1 == 3){
                    if(doktrin2 == 4)
                        cout << "as asker, yoldaşa " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "as asker, piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "komando, yoldaşa " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    else
                        cout << "komando, piyadeye " << (saldiran/1e+12-30) << " hasar verdi." << endl;
                    
                }
            }else if(saldiran/1e+13==4){
                if(doktrin1 == 4){
                    if(doktrin2 == 4)
                        cout << "panther, yoldaşa " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "panther, piyadeye " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                }else{
                    if(doktrin2 == 4)
                        cout << "tank, yoldaşa " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    else
                        cout << "tank, piyadeya " << (saldiran/1e+12-40) << " hasar verdi." << endl;
                    
                }
            }

        }
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

void ciftesaldiri(){
    if(secim1 == "A1")
        sA1++;
    else if(secim1 == "A2")
        sA2++;
    else if(secim1 == "A3")
        sA3++;
    else if(secim1 == "A4")
        sA4++;
    else if(secim1 == "A5")
        sA5++;
    else if(secim1 == "B1")
        sB1++;
    else if(secim1 == "B2")
        sB2++;
    else if(secim1 == "B2")
        sB3++;
    else if(secim1 == "B4")
        sB4++;
    else if(secim1 == "B5")
        sB5++;
    
}


long hasarin(long saldiran){
    hasar = saldiran/1e+12-(saldiran/1e+13)*10;
    return hasar;
}

void savas(){
    saldiri_hakki1();
    
    
    if(saldiri_hakki==1){
        if(secim2 == "rakip üs"){
            if(hamle_sirasi == "player1")                                                       //KARŞI ANA ÜSSE SALDIRI
                cephe[5][1] = cephe[5][1] - hasarin(saldiran);
            else
                cephe[5][0] = cephe[5][0] - hasarin(saldiran);
                sistem4rakipus();
        }else{
            if(cephe[savunan1][savunan2]/1e+6-cephe[savunan1][savunan2]/(1e+7)*10 == 1)            //DAYANIKLIYA SALDIRI
                cephe[savunan1][savunan2] = cephe[savunan1][savunan2] - (hasarin(saldiran)-1);
            else
                cephe[savunan1][savunan2] = cephe[savunan1][savunan2] - hasarin(saldiran);            //NORMAL SALDIRI
            if(cephe[savunan1][savunan2]/1e+12 != savunan/1e+12){                                     //OLÜM
                cephe[savunan1][savunan2]=0;
                sistem2olum();
                if(saldiran/1e+4-saldiran/1e+6*100 == 11){                                           //ÇİFTE SALDIRI
                    cephe[saldiran1][saldiran2]-=10000;
                    ciftesaldiri();
                }
            }
            else if(cephe[savunan1][savunan2]/1e11-cephe[savunan1][savunan2]/1e+12*10 == 0){             //ÖLÜM2
                cephe[savunan1][savunan2]=0;
                sistem2olum();
            }else
                sistem3hasar();                                                                           //HASAR
        }
        
    }else{
        cout << "bu birim bu tur saldıramaz!" << endl;                                                    //saldırı hakkı
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
                cin >> secim1;
                if(secim1 == "A1"){
                    saldiran= cephe[0][0];
                    saldiran1=0;
                    saldiran2=0;
                }
                else if(secim1 == "A2"){
                    saldiran = cephe[1][0];
                    saldiran1=1;
                    saldiran2=0;
                }
                else if(secim1 == "A3"){
                    saldiran = cephe[2][0];
                    saldiran1=2;
                    saldiran2=0;
                }
                else if(secim1 == "A4"){
                    saldiran = cephe[3][0];
                    saldiran1=3;
                    saldiran2=0;
                }
                else if(secim1 == "A5"){
                    saldiran = cephe[4][0];
                    saldiran1=4;
                    saldiran2=0;
                }
                else if(secim1 == "geri"){
                    geri++;
                    break;
                }else{
                    cout << "1birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(saldiran == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
                if(donusturucu2(saldiran/1e+9 , saldiran/1e+10) == 5){                                    //menzil 5 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        cout << "herhangi bir rakip seç(B1/B2/B3/B4/B5/rakip üs/geri):";
                        getline(cin,secim2);
                    }else{
                        cout << "herhangi bir rakip seç(B1/B2/B3/B4/B5/geri):";
                        getline(cin,secim2);
                    }
                }
                else if(donusturucu2(saldiran/1e+9 , saldiran/1e+10) == 3){                                //menzil 3 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        if(secim1 == "A1"){
                            cout << "herhangi bir rakip seç(B1/B2/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A2"){
                            cout << "herhangi bir rakip seç(B1/B2/B3/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A3"){
                            cout << "herhangi bir rakip seç(B2/B3/B4/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A4"){
                            cout << "herhangi bir rakip seç(B3/B4/B5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A5"){
                            cout << "herhangi bir rakip seç(B4/B5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                    }
                    else{
                        if(secim1 == "A1"){
                            cout << "herhangi bir rakip seç(B1/B2/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A2"){
                            cout << "herhangi bir rakip seç(B1/B2/B3/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A3"){
                            cout << "herhangi bir rakip seç(B2/B3/B4/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A4"){
                            cout << "herhangi bir rakip seç(B3/B4/B5/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A5"){
                            cout << "herhangi bir rakip seç(B4/B5/geri):";
                            getline(cin,secim2);
                        }

                    }
                }
                else if(donusturucu2(saldiran/1e+9 , saldiran/1e+10) == 1){                                //menzil 1 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        if(secim1 == "A1"){
                            cout << "herhangi bir rakip seç(B1/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A2"){
                            cout << "herhangi bir rakip seç(B2/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A3"){
                            cout << "herhangi bir rakip seç(B3/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A4"){
                            cout << "herhangi bir rakip seç(B4/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A5"){
                            cout << "herhangi bir rakip seç(B5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                    }
                    else{
                        if(secim1 == "A1"){
                            cout << "herhangi bir rakip seç(B1/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A2"){
                            cout << "herhangi bir rakip seç(B2/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A3"){
                            cout << "herhangi bir rakip seç(B3/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A4"){
                            cout << "herhangi bir rakip seç(B4/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "A5"){
                            cout << "herhangi bir rakip seç(B5/geri):";
                            getline(cin,secim2);
                        }
                    }
                }
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
                    cout << "2birimin konumunu doğru belirttiğinizden emin olun!" << endl;
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
    
                if(secim1== "B1"){
                    saldiran = cephe[0][1];
                    saldiran1=0;
                    saldiran2=1;
                }
                else if(secim1 == "B2"){
                    saldiran = cephe[1][1];
                    saldiran1=1;
                    saldiran2=1;
                }
                else if(secim1 == "B3"){
                    saldiran = cephe[2][1];
                    saldiran1=2;
                    saldiran2=1;
                }
                else if(secim1 == "B4"){
                    saldiran = cephe[3][1];
                    saldiran1=3;
                    saldiran2=1;
                }
                else if(secim1 == "B5"){
                    saldiran = cephe[4][1];
                    saldiran1=4;
                    saldiran2=1;
                }
                else if(secim1 == "geri"){
                    geri++;
                    break;
                }
                else{
                    cout << "3birimin konumunu doğru belirttiğinizden emin olun!" << endl;
                    c++;
                    break;
                }
                if(saldiran == 0){
                    cout << "seçtiğiniz konumda birim bulunmamaktadır!" << endl;
                    c++;
                    break;
                }
                if(saldiran/1e+9-saldiran/1e+10 == 5){                                    //menzil 5 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        cout << "herhangi bir rakip seç(A1/A2/A3/A4/A5/rakip üs/geri):";
                        getline(cin,secim2);
                    }else{
                        cout << "herhangi bir rakip seç(A1/A2/A3/A4/A5/geri):";
                        getline(cin,secim2);
                    }
                }
                else if(saldiran/1e+9-saldiran/1e+10 == 3){                                //menzil 3 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        if(secim1 == "B1"){
                            cout << "herhangi bir rakip seç(A1/A2/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B2"){
                            cout << "herhangi bir rakip seç(A1/A2/A3/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B3"){
                            cout << "herhangi bir rakip seç(A2/A3/A4/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B4"){
                            cout << "herhangi bir rakip seç(A3/A4/A5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B5"){
                            cout << "herhangi bir rakip seç(A4/A5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                    }
                    else{
                        if(secim1 == "B1"){
                            cout << "herhangi bir rakip seç(A1/A2/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B2"){
                            cout << "herhangi bir rakip seç(A1/A2/A3/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B3"){
                            cout << "herhangi bir rakip seç(A2/A3/A4/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B4"){
                            cout << "herhangi bir rakip seç(A3/A4/A5/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B5"){
                            cout << "herhangi bir rakip seç(A4/A5/geri):";
                            getline(cin,secim2);
                        }

                    }
                }
                else if(saldiran/1e+9-saldiran/1e+10 == 1){                                //menzil 1 ise
                    if(cephe[saldiran1][saldiran2+1] == 0){
                        if(secim1 == "B1"){
                            cout << "herhangi bir rakip seç(A1/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B2"){
                            cout << "herhangi bir rakip seç(A2/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B3"){
                            cout << "herhangi bir rakip seç(A3/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B4"){
                            cout << "herhangi bir rakip seç(A4/ana üs/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B5"){
                            cout << "herhangi bir rakip seç(A5/ana üs/geri):";
                            getline(cin,secim2);
                        }
                    }
                    else{
                        if(secim1 == "B1"){
                            cout << "herhangi bir rakip seç(A1/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B2"){
                            cout << "herhangi bir rakip seç(A2/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B3"){
                            cout << "herhangi bir rakip seç(A3/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B4"){
                            cout << "herhangi bir rakip seç(A4/geri):";
                            getline(cin,secim2);
                        }
                        else  if(secim1 == "B5"){
                            cout << "herhangi bir rakip seç(A5/geri):";
                            getline(cin,secim2);
                        }
                    }
                }
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
                    cout << "4birimin konumunu doğru belirttiğinizden emin olun!" << endl;
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
    if(hamle_sirasi == "player1"){
        if(yerlestirme == "A1"){
            if(birim == "piyade"){
                if(doktrin1 == 1){
                    if(donusturucu1(cephe[0][0]/1e13)== 1)
                        cephe[0][0]+=1e11;
                    else
                        cephe[0][0] = piyade1;
                    askereal++;
                }else{
                    cephe[0][0] = piyade1;
                }
                if(donusturucu2(piyade1/1e+5 , piyade1/1e+6) == 1)
                    sA1=1;
                if(askereal == 4){
                    askereal-=4;
                    para1++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[0][0] = mekanize1;
                if(donusturucu2(mekanize1/1e+5 , mekanize1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "komando"){
                cephe[0][0] = komando1;
                if(donusturucu2(komando1/1e+5 , komando1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "tank"){
                cephe[0][0] = tank1;
                if(donusturucu2(tank1/1e+5 , tank1/1e+6) == 1)
                    sA1=1;
            }
            
        }
        else if(yerlestirme == "A2"){
            if(birim == "piyade"){
                if(doktrin1 == 1){
                    if(donusturucu1(cephe[1][0]/1e13)== 1)
                        cephe[1][0]+=1e11;
                    else
                        cephe[1][0] = piyade1;
                    askereal++;
                }else{
                    cephe[1][0] = piyade1;
                }
                if(donusturucu2(piyade1/1e+5 , piyade1/1e+6) == 1)
                    sA1=1;
                if(askereal == 4){
                    askereal-=4;
                    para1++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[1][0] = mekanize1;
                if(donusturucu2(mekanize1/1e+5 , mekanize1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "komando"){
                cephe[1][0] = komando1;
                if(donusturucu2(komando1/1e+5 , komando1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "tank"){
                cephe[1][0] = tank1;
                if(donusturucu2(tank1/1e+5 , tank1/1e+6) == 1)
                    sA1=1;
            }
            
        }
        else if(yerlestirme == "A3"){
            if(birim == "piyade"){
                if(doktrin1 == 1){
                    if(donusturucu1(cephe[2][0]/1e13)== 1)
                        cephe[2][0]+=1e11;
                    else
                        cephe[2][0] = piyade1;
                    askereal++;
                }else{
                    cephe[2][0] = piyade1;
                }
                if(donusturucu2(piyade1/1e+5 , piyade1/1e+6) == 1)
                    sA1=1;
                if(askereal == 4){
                    askereal-=4;
                    para1++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[2][0] = mekanize1;
                if(donusturucu2(mekanize1/1e+5 , mekanize1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "komando"){
                cephe[2][0] = komando1;
                if(donusturucu2(komando1/1e+5 , komando1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "tank"){
                cephe[2][0] = tank1;
                if(donusturucu2(tank1/1e+5 , tank1/1e+6) == 1)
                    sA1=1;
            }
            
        }
        else if(yerlestirme == "A4"){
            if(birim == "piyade"){
                if(doktrin1 == 1){
                    if(donusturucu1(cephe[3][0]/1e13)== 1)
                        cephe[3][0]+=1e11;
                    else
                        cephe[3][0] = piyade1;
                    askereal++;
                }else{
                    cephe[3][0] = piyade1;
                }
                if(donusturucu2(piyade1/1e+5 , piyade1/1e+6) == 1)
                    sA1=1;
                if(askereal == 4){
                    askereal-=4;
                    para1++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[3][0] = mekanize1;
                if(donusturucu2(mekanize1/1e+5 , mekanize1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "komando"){
                cephe[3][0] = komando1;
                if(donusturucu2(komando1/1e+5 , komando1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "tank"){
                cephe[3][0] = tank1;
                if(donusturucu2(tank1/1e+5 , tank1/1e+6) == 1)
                    sA1=1;
            }
            
        }
        else if(yerlestirme == "A5"){
            if(birim == "piyade"){
                if(doktrin1 == 1){
                    if(donusturucu1(cephe[4][0]/1e13)== 1)
                        cephe[4][0]+=1e11;
                    else
                        cephe[4][0] = piyade1;
                    askereal++;
                }else{
                    cephe[4][0] = piyade1;
                }
                if(donusturucu2(piyade1/1e+5 , piyade1/1e+6) == 1)
                    sA1=1;
                if(askereal == 4){
                    askereal-=4;
                    para1++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[4][0] = mekanize1;
                if(donusturucu2(mekanize1/1e+5 , mekanize1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "komando"){
                cephe[4][0] = komando1;
                if(donusturucu2(komando1/1e+5 , komando1/1e+6) == 1)
                    sA1=1;
            }
            else if(birim == "tank"){
                cephe[4][0] = tank1;
                if(donusturucu2(tank1/1e+5 , tank1/1e+6) == 1)
                    sA1=1;
            }
        }
    }else{
        if(yerlestirme == "B1"){
            if(birim == "piyade"){
                if(doktrin2 == 1){
                    if(donusturucu1(cephe[0][1]/1e13)== 1)
                        cephe[0][1]+=1e11;
                    else
                        cephe[0][1] = piyade2;
                    askereal++;
                }else{
                    cephe[0][1] = piyade2;
                }
                if(donusturucu2(piyade2/1e+5 , piyade2/1e+6) == 1)
                    sB1=1;
                if(askereal == 4){
                    askereal-=4;
                    para2++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[0][1] = mekanize2;
                if(donusturucu2(mekanize2/1e+5 , mekanize2/1e+6) == 1)
                    sB1=1;
            }
            else if(birim == "komando"){
                cephe[0][1] = komando2;
                if(donusturucu2(komando2/1e+5 , komando2/1e+6) == 1)
                    sB1=1;
            }
            else if(birim == "tank"){
                cephe[0][1] = tank2;
                if(donusturucu2(tank2/1e+5 , tank2/1e+6) == 1)
                    sB1=1;
            }
            
        }
        else if(yerlestirme == "B2"){
            if(birim == "piyade"){
                if(doktrin2 == 1){
                    if(donusturucu1(cephe[1][1]/1e13)== 1)
                        cephe[1][1]+=1e11;
                    else
                        cephe[1][1] = piyade2;
                    askereal++;
                }else{
                    cephe[1][1] = piyade2;
                }
                if(donusturucu2(piyade2/1e+5 , piyade2/1e+6) == 1)
                    sB2=1;
                if(askereal == 4){
                    askereal-=4;
                    para2++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[1][1] = mekanize2;
                if(donusturucu2(mekanize2/1e+5 , mekanize2/1e+6) == 1)
                    sB2=1;
            }
            else if(birim == "komando"){
                cephe[1][1] = komando2;
                if(donusturucu2(komando2/1e+5 , komando2/1e+6) == 1)
                    sB2=1;
            }
            else if(birim == "tank"){
                cephe[1][1] = tank2;
                if(donusturucu2(tank2/1e+5 , tank2/1e+6) == 1)
                    sB2=1;
            }
            
        }
        else if(yerlestirme == "B3"){
            if(birim == "piyade"){
                if(doktrin2 == 1){
                    if(donusturucu1(cephe[2][1]/1e13)== 1)
                        cephe[2][1]+=1e11;
                    else
                        cephe[2][1] = piyade2;
                    askereal++;
                }else{
                    cephe[2][1] = piyade2;
                }
                if(donusturucu2(piyade2/1e+5 , piyade2/1e+6) == 1)
                    sB3=1;
                if(askereal == 4){
                    askereal-=4;
                    para2++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[2][1] = mekanize2;
                if(donusturucu2(mekanize2/1e+5 , mekanize2/1e+6) == 1)
                    sB3=1;
            }
            else if(birim == "komando"){
                cephe[2][1] = komando2;
                if(donusturucu2(komando2/1e+5 , komando2/1e+6) == 1)
                    sB3=1;
            }
            else if(birim == "tank"){
                cephe[2][1] = tank2;
                if(donusturucu2(tank2/1e+5 , tank2/1e+6) == 1)
                    sB3=1;
            }
            
        }
        else if(yerlestirme == "B4"){
            if(birim == "piyade"){
                if(doktrin2 == 1){
                    if(donusturucu1(cephe[3][1]/1e13)== 1)
                        cephe[3][1]+=1e11;
                    else
                        cephe[3][1] = piyade2;
                    askereal++;
                }else{
                    cephe[3][1] = piyade2;
                }
                if(donusturucu2(piyade2/1e+5 , piyade2/1e+6) == 1)
                    sB4=1;
                if(askereal == 4){
                    askereal-=4;
                    para2++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[3][1] = mekanize2;
                if(donusturucu2(mekanize2/1e+5 , mekanize2/1e+6) == 1)
                    sB4=1;
            }
            else if(birim == "komando"){
                cephe[3][1] = komando2;
                if(donusturucu2(komando2/1e+5 , komando2/1e+6) == 1)
                    sB4=1;
            }
            else if(birim == "tank"){
                cephe[3][1] = tank2;
                if(donusturucu2(tank2/1e+5 , tank2/1e+6) == 1)
                    sB4=1;
            }
            
        }
        else if(yerlestirme == "B5"){
            if(birim == "piyade"){
                if(doktrin2 == 1){
                    if(donusturucu1(cephe[4][1]/1e13)== 1)
                        cephe[4][1]+=1e11;
                    else
                        cephe[4][1] = piyade2;
                    askereal++;
                }else{
                    cephe[4][1] = piyade2;
                }
                if(donusturucu2(piyade2/1e+5 , piyade2/1e+6) == 1)
                    sB5=1;
                if(askereal == 4){
                    askereal-=4;
                    para2++;
                }
            }
            else if(birim == "mekanize piyade"){
                cephe[4][1] = mekanize2;
                if(donusturucu2(mekanize2/1e+5 , mekanize2/1e+6) == 1)
                    sB5=1;
            }
            else if(birim == "komando"){
                cephe[4][1] = komando2;
                if(donusturucu2(komando2/1e+5 , komando2/1e+6) == 1)
                    sB5=1;
            }
            else if(birim == "tank"){
                cephe[4][1] = tank2;
                if(donusturucu2(tank2/1e+5 , tank2/1e+6) == 1)
                    sB5=1;
            }
            
        }
    }
}

int para_kullanimi(){
    if(hamle_sirasi == "player1"){
            if(birim == "komando"){
                if(para1 >= donusturucu2(komando1/1e10 , komando1/1e11))
                    para1-=donusturucu2(komando1/1e10 , komando1/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }
            else if(birim == "piyade"){
                if(para1 >= donusturucu2(piyade1/1e10 , piyade1/1e11))
                    para1 -= donusturucu2(piyade1/1e10 , piyade1/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }else if(birim == "mekanize piyade"){
                if(para1 >= donusturucu2(mekanize1/1e10 , mekanize1/1e11))
                    para1-=donusturucu2(mekanize1/1e10 , mekanize1/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }else if(birim == "tank"){
                if(para1 >= donusturucu2(tank1/1e10 , tank1/1e11))
                    para1-=donusturucu2(tank1/1e10 , tank1/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }
        }
       
    else if(hamle_sirasi == "player2"){
            if(birim == "komando"){
                if(para2 >= donusturucu2(komando2/1e10 , komando2/1e11))
                    para2-=donusturucu2(komando2/1e10 , komando2/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }
            else if(birim == "piyade"){
                if(para2 >= donusturucu2(piyade2/1e10 , piyade2/1e11))
                    para2 -= donusturucu2(piyade2/1e10 , piyade2/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }else if(birim == "mekanize piyade"){
                if(para2 >= donusturucu2(mekanize2/1e10 , mekanize2/1e11))
                    para2-=donusturucu2(mekanize2/1e10 , mekanize2/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
            }else if(birim == "tank"){
                if(para2 >= donusturucu2(tank2/1e10 , tank2/1e11))
                    para2-=donusturucu2(tank2/1e10 , tank2/1e11);
                else{
                    cout << "paranız yeterli değil!" << endl;
                    geri++;
                }
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
            
        }else{
            
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


