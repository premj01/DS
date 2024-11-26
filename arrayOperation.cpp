#include <iostream>
using namespace std;

class Array
{
private:
    int *arr, end, size;

public:
    Array(int size)
    {
        arr = new int[size];
        end = -1;
        this->size = size;
    }
    int insert(int data)
    {
        if (end >= size - 1)
        {
            cout << "Array is full" << endl;
            return 0;
        }
        arr[++end] = data;
        return data;
    }
    int insert(int index, int data)
    {
        if (index > end + 1 || index >= size)
        {
            cout << "Invalid index" << endl;
            return 0;
        }
        for (int i = end; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = data;
        end++;
        return data;
    }
    int deleteEle()
    {
        if (end < 0)
        {
            cout << "Array is empty" << endl;
            return 0;
        }
        end--;
        return arr[end + 1];
    }
    int deleteIdx(int index)
    {
        if (index > end || index < 0)
        {
            cout << "Invalid index" << endl;
            return 0;
        }
        int data = arr[index];
        for (int i = index; i < end; i++)
        {
            arr[i] = arr[i + 1];
        }
        end--;
        return data;
    }
    void display()
    {
        cout << "array :{ ";
        for (int i = 0; i <= end; i++)
        {
            cout << arr[i];
            if (i < end)
                cout << " , ";
        }
        cout << " }" << endl;
    }
};

int main()
{
    Array *a = new Array(5);
    while(true)
    {
        cout<<"1.Insert at end"<<endl;
        cout<<"2.Insert at any index"<<endl;
        cout<<"3.delete at end"<<endl;
        cout<<"4.delete at any index"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl;

        int input ;
        cin>>input;

        int data,idx; 
        switch(input)
        {
            case 1: 
                    cout<<"Enter the Value";
                    cin>>data;
                    a->insert(data);
                    break;
            case 2: 
                    cout<<"Enter the Index";
                    cin>>idx;
                    a->insert(idx , data);
                    cout<<"Enter the Value";
                    cin>>data;
                    a->insert(data);
                    break;
            case 3: 
                    cout<<a->deleteEle()<<" Deleted Successfully"<<endl;
                    break;
            case 4: 
                    cout<<"Enter index :";
                    cin>>idx;
                    cout<<a->deleteIdx(idx)<<" Deleted Successfully"<<endl;
                    break;
            case 5: 
                    a->display();
                    break;
            case 6: 
                    exit(0);
            default: cout<<"PLEASE ENTER VALID CHOICE !!!"<<endl;
            
            
        }
        
    }

    return 0;
}
