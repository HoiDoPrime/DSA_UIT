#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void Nhap(DATHUC &B,double heso,int somu){
    DONTHUC * donthuc= new DONTHUC(heso,somu);
    Node* newNode = new Node(donthuc);
    
    if (B.head == nullptr) {
        B.head = B.tail = newNode;
    } else {
        B.tail->next = newNode;
        B.tail = newNode;
    }
}
void Xuat(DATHUC B){
    Node* curr = B.head;
    int dem = 0;
    int i = 0;

    while(curr != nullptr){
        if(curr->data->heso != 0){
            if(curr->data->heso > 0 && i != 0){
                cout << "+";
            }
            
            // Check for heso being 1 or -1 separately
            if(curr->data->heso == -1){
                cout << "-";
            } else if(curr->data->heso != 1){
                cout << curr->data->heso;
            }
            if(curr->data->heso==-1 && curr->data->somu==0){
                cout<<1;
            }

            if(curr->data->somu != 0){
                cout << "x";
                if(curr->data->somu != 1){
                    cout << "^" << curr->data->somu;
                }
            }
            dem++;
            i++;
        }
        curr = curr->next;
    }
   
    if(dem == 0) cout << 0;
}

double TinhDaThuc(DATHUC B,double x){
    double result = 0;
    Node* current = B.head;
    while (current != nullptr) {
        result += current->data->heso * pow(x, current->data->somu);
        current = current->next;
    }
    return result;

}
int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
