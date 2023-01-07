#include<iostream>
#include<fstream>

using namespace std;

class shopping{
private:
    int pcode;
    float price, dis;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};

void shopping :: menu(){
m:
    int choice;
    string email, password;
    cout<<"\t\t\t\t_______________________________"<<endl;
    cout<<"\t\t\t\t|                             |"<<endl;
    cout<<"\t\t\t\t|    Supermarket Main Menu    |"<<endl;
    cout<<"\t\t\t\t|                             |"<<endl;
    cout<<"\t\t\t\t|_____________________________|"<<endl;
    cout<<"\t\t\t\t                             "<<endl;
    cout<<"\t\t\t\t       1) Administrator       "<<endl;
    cout<<"\t\t\t\t                              "<<endl;
    cout<<"\t\t\t\t       2) Buyer               "<<endl;
    cout<<"\t\t\t\t                              "<<endl;
    cout<<"\t\t\t\t       3) Exit                "<<endl;
    cout<<"\t\t\t                            "<<endl;
    cout<<"\t\t\t Please select any of the above: "<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:
            cout<<"\t\t\t\t Please Login!         "<<endl;
            cout<<"\t\t\t Enter email:          "<<endl;
            cin>>email;
            cout<<"\n\t\t\t Enter Password:       "<<endl;
            cin>>password;
            if(email=="smsprince2@gmail.com" and password== "prince@123"){
                administrator();
                break;
            }
            else
                cout<<"\t\t\t Invalid Entry!      "<<endl;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout<<"\t\t\t Please Enter the correct choice!"<<endl;
    }
    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t\t Administrator menu    "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t      1) Add Product         "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t      2) Edit Product        "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t      3) Delete Product      "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t      4) Back to main menu   "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t   Please Enter your choice  "<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"\n\t\t\t Invalid Choice        "<<endl;
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c, token=0;
    float p,d;
    string n;
    cout<<"\n\n\n\t\t\t\t Add new Product       "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t  Product code:  "<<endl;
    cin>>pcode;
    cout<<"\n\t\t\t  Name:             "<<endl;
    cin>>pname;
    cout<<"\n\t\t\t  Price:             "<<endl;
    cin>>price;
    cout<<"\n\t\t\t  Discount on Product   "<<endl;
    cin>>dis;
    data.open("database.txt", ios::in);
    if(!data){
        data.open("database.txt", ios::app| ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==pcode)
                token++;
            data>>c>>n>>p>>d;
            
        }
        
        data.close();
        if(token==1)
            goto m;
        else{
            data.open("database.txt", ios::app| ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
            data.close();
        }
    }
    cout<<"\n\t\t  Record inserted "<<endl;
}

void shopping :: buyer(){
m:
    int choice;
    cout<<"\t\t\t  Hello there           "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t  1) Buy Product            "<<endl;
    cout<<"\t\t\t                            "<<endl;
    cout<<"\t\t\t  2) Go back                "<<endl;
    cout<<"\t\t\t                            "<<endl;
    cout<<"\t\t\t  Enter your choice:        "<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            reciept();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"\n\t\t\t  Invalid choice  "<<endl;
            
    }
    goto m;
    
}

void shopping :: edit(){
    fstream data,data1;
    int pkey, token=0, c;
    string n;
    float p, d;
    cout<<"\n\t\t\t  Modify Record      "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t  Product code:    "<<endl;
    cin>>pkey;
    data.open("database.txt", ios:: in);
    if(!data)
        cout<<"\n\n \t\t\t File doesn't exist! "<<endl;
    else{
        data1.open("database1.txt", ios:: app | ios :: out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t\t  Product new code:   "<<endl;
                cin>>c;
                cout<<"\n\t\t\t  Name of product:     "<<endl;
                cin>>n;
                cout<<"\n\t\t\t  Price:             "<<endl;
                cin>>p;
                cout<<"\n\t\t\t  Discount:           "<<endl;
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t  Record edited!       "<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if(token ==0)
            cout<<"\n\t\t\t  Record not found sorry!   "<<endl;
        }
}

void shopping :: rem(){
    fstream data, data1;
    int pkey, token=0;
    cout<<"\n\t\t\t  Delete Product            "<<endl;
    cout<<"\t\t\t                             "<<endl;
    cout<<"\t\t\t  Product Code:          "<<endl;
    cin>>pkey;
    data.open("database.txt", ios:: in);
    if(!data)
        cout<<"\n\t\t\t  File doesn't exist ";
    else{
        data1.open("database1.txt", ios:: app | ios:: out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\t\t\t                             "<<endl;
                cout<<"\t\t\t  Product deleted Successfully!     "<<endl;
                token++;
            }
            else
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            
            data>>pcode>>pname>>price>>dis;
            
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if(token==0){
            cout<<"\n\t\t\t  Record not found!          "<<endl;
        }
    }
}

void shopping :: list(){
    fstream data;
    data.open("database.txt", ios :: in);
    cout<< "\n\t Product Number \t\t Name \t\t Price \n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<" \t\t " <<pname<< " \t\t "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: reciept(){
    
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0, dis=0, total=0;
    
    cout<<"\n\n\t\t\t\t RECEIPT     "<<endl;
    data.open("database.txt", ios :: in);
    
    if(!data)
        cout<<"\n\n \t\t\t Empty Database!  "<<endl;
    else{
        data.close();
        list();
        cout<<"\n\t\t\t\t________________________________"<<endl;
        cout<<"\t\t\t                             "<<endl;
        cout<<"\t\t\t\t  Please place the order      "<<endl;
        cout<<"\n\t\t\t\t________________________________"<<endl;
        
        do{
        m:
            cout<<"\n\n\t\t\t Enter the product code:   "<<endl;
            cin>>arrc[c];
            cout<<"\n\n\t\t\t Enter the quantity:       "<<endl;
            cin>>arrq[c];
            for(int i=0; i<c; i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n\t\t\t Duplicate product code"<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"\n\n\t\t\t Do you want to buy another product ? Y for Yes and N for No";
            cin>>choice;
        }
        while(choice=='Y');{
            cout<<"\n\n\t\t\t___________RECIEPT_____________"<<endl;
            cout<<"\n Product No. \t\t Product Name \t\t Product quantity \t\t Price \t\t Amount \t\t Amount with discount"<<endl;
            for(int i=0; i<c; i++){
                data.open("database.txt", ios:: in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof()){
                    if(pcode==arrc[i]){
                        amount=price*arrq[i];
                        dis=amount-amount*dis/100;
                        total+=dis;
                        cout<<"\n\n\t\t"<<pcode<<" \t\t "<<pname<<" \t\t "<<arrq[i]<<" \t\t "<<price<<" \t\t "<<amount<<" \t\t "<<dis<<endl;
                        
                    }
                    data>>pcode>>pname>>price>>dis;
                }
                
            }
            
        }
        data.close();
    }
        cout<<"\n\n\t\t\t_________________________________"<<endl;
        cout<<"\n\t\t Total amount: "<<total;
    
}

int main(){
    shopping s;
    s.menu();
    return 0;
}

