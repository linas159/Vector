Testavimas su funkcijomis:


vector::swap

Testavimo kodas:

    std::vector<int> foo(3, 100);
    std::vector<int> bar(5, 200);

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << '\n';

    Vector<int> foo1(3, 100);
    Vector<int> bar1(5, 200);

    foo1.swap(bar1);

    std::cout << "foo1 contains:";
    for (unsigned i = 0; i < foo1.size(); i++)
        std::cout << ' ' << foo1[i];
    std::cout << '\n';

    std::cout << "bar1 contains:";
    for (unsigned i = 0; i < bar1.size(); i++)
        std::cout << ' ' << bar1[i];
    std::cout << '\n';
    
 Rezultatas:
 
    foo contains: 200 200 200 200 200
    bar contains: 100 100 100
    foo1 contains: 200 200 200 200 200
    bar1 contains: 100 100 100
    
    
vector::shrink_to_fit

Testavimo kodas:

    std::vector<int> v (100);
    std::cout << "1. capacity of v: " << v.capacity() << '\n';

    v.resize(10);
    std::cout << "2. capacity of v: " << v.capacity() << '\n';

    v.shrink_to_fit();
    std::cout << "3. capacity of v: " << v.capacity() << '\n';


    Vector<int> v1 (100);
    std::cout << "1. capacity of v1: " << v1.capacity() << '\n';

    v1.resize(10);
    std::cout << "2. capacity of v1: " << v1.capacity() << '\n';

    v1.shrink_to_fit();
    std::cout << "3. capacity of v1: " << v1.capacity() << '\n';
Rezultatas:

    1. capacity of v: 100
    2. capacity of v: 100
    3. capacity of v: 10
    1. capacity of v1: 100
    2. capacity of v1: 100
    3. capacity of v1: 10
    
    
vector::resize

Testavimo kodas:

    std::vector<int> v;

    for (int i=1;i<10;i++) v.push_back(i);

    v.resize(5);
    v.resize(8,100);
    v.resize(12);

    std::cout << "v contains:";
    for (int i=0;i<v.size();i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';


    Vector<int> v1;

    for (int i=1;i<10;i++) v1.push_back(i);

    v1.resize(5);
    v1.resize(8,100);
    v1.resize(12);

    std::cout << "v1 contains:";
    for (int i=0;i<v1.size();i++)
        std::cout << ' ' << v1[i];
    std::cout << '\n';
Rezultatas:

    v contains: 1 2 3 4 5 100 100 100 0 0 0 0
    v1 contains: 1 2 3 4 5 100 100 100 0 0 0 0


vector::erase

Testavimo kodas:

    std::vector<int> v;

    for (int i=1; i<=10; i++) v.push_back(i);

    v.erase (v.begin()+5);

    v.erase (v.begin(),v.begin()+3);

    std::cout << "v contains:";
    for (unsigned i=0; i<v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';


    Vector<int> v1;

    for (int i=1; i<=10; i++) v1.push_back(i);

    v1.erase (v1.begin()+5);

    v1.erase (v1.begin(),v1.begin()+3);

    std::cout << "v1 contains:";
    for (unsigned i=0; i<v1.size(); ++i)
        std::cout << ' ' << v1[i];
    std::cout << '\n';
Rezultatas:

    v contains: 4 5 7 8 9 10
    v1 contains: 4 5 7 8 9 10
    
    
vector::empty

Testavimo kodas:

    std::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

    Vector<int> numbers1;
    std::cout << "Initially, numbers1.empty(): " << numbers1.empty() << '\n';

    numbers.push_back(42);
    std::cout << "After adding elements, numbers1.empty(): " << numbers1.empty() << '\n';
        
Rezultatas:

    Initially, numbers.empty(): 1
    After adding elements, numbers.empty(): 0
    Initially, numbers1.empty(): 1
    After adding elements, numbers1.empty(): 0


Greicio lyginimas


Testavimo kodas:

    void pushtestas1(int sz)
    {
        auto start = chrono::high_resolution_clock::now();
        std::vector<int> v1;
        for (int i = 1; i <= sz; ++i)
            v1.push_back(i);
        auto duration = duration_cast<microseconds>(chrono::high_resolution_clock::now() - start);
        cout << sz << " std::vector uztruko: " << float(duration.count()) / 1000000 << endl;
    }
    void pushtestas2(int sz)
    {
        auto start = chrono::high_resolution_clock::now();
        Vector<int> v2;
        for (int i = 1; i <= sz; ++i)
            v2.push_back(i);
        auto duration = duration_cast<microseconds>(chrono::high_resolution_clock::now() - start);
        cout <<sz<< " Vector uztruko: " << float(duration.count()) / 1000000<<endl;
    }
    
    int main()
    {
       for (int i = 10000; i <= 100000000; i *= 10)
       {
           pushtestas1(i);
       }
       cout << endl;
       for (int i = 10000; i <= 100000000; i *= 10)
       {
           pushtestas2(i);
       }
    }
  
 Rezultatai:
 
![image](https://user-images.githubusercontent.com/93277316/170740112-0015bb82-f736-4390-95a1-cab0b261d32b.png)
