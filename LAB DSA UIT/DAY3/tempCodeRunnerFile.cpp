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