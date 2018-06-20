/*
#include <iostream>
#include <csignal>
#include<unistd.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;
*/
/*
#include<iostream>
#include<string>

using namespace std;



double div(double a,double b)
{
	if(!b)
		throw "Division by zero error";
	if(b==1)
		throw "Just kidding!";
	return a/b;
}


int main()
{
	double a,b,c;
	cin>>a>>b;
	try
	{
		c=div(a,b);
		cout<<c<<endl;	
	}

	catch(const char* msg)
	{
		cout<<msg<<endl;
	}
	

}
*/

/*
template <class T>

class Rectangle
{
private:
	T length;
	T breadth;

public:
	void setLength(T len)
	{
		length=len;
	}

	void setBreadth(T bre)
	{
		breadth=bre;
	} 

	T getArea()
	{
		return length*breadth;
	}
};


int main()
{
	Rectangle<double> a;
	a.setLength(10.22);
	a.setBreadth(20.22);

	cout<<a.getArea()<<endl;
}
*/


/*
using namespace std;

void signalHand( int sig ) {
   cout << "Interrupt signal (" << sig << ") received.\n";

   // cleanup and close up stuff here  
   // terminate program  

   exit(sig);  
}

int main () {
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHand);  

   while(1) {
      cout << "Going to sleep...." << endl;
      sleep(1);
   }

   return 0;
}
*/
/*


class Temp
{
protected:
	int length;
	int breadth;

public:	
	void setLength(int len)
	{
		length=len;
	}

	void setBreadth(int bre)
	{
		breadth=bre;
	}
};

class Derive:public Temp
{
public:
	int getArea()
	{
		return length*breadth;
	}
};

int main()
{
	Derive t;
	t.setBreadth(10);
	t.setLength(20);

	cout<<"Area is:"<<t.getArea()<<endl;
}

*/
/*
int main()
{
	vector<int> v;
	int j;
	for(int i=0;i<5;i++)
	{
		cin>>j;
		v.push_back(j);
	}
	//cout<<v.size()<<endl;

	vector<int>::iterator vec=v.begin();

	while(vec!=v.end())
	{
		cout<<"Value is: "<<*vec<<endl;
		vec++;
	}
}
*/


/*
void print(int a[])
{
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
}

int main()
{
	int arr[5]={1,2,3,4,5};
	int arr1[5];

	_gnu_cxx::copy_n(arr,5,arr1);
	arr1[2]=15;

	print(arr);cout<<"\n";
	print(arr1);

}

*/


#include <sstream>
#include <vector>
#include <iostream>
#include<string>
#include<limits.h>
using namespace std;


/*
int max(int a,int b)
{
	return (a>b)?a:b;
}

int max(int a,int b,int c)
{
	return max(max(a,b),c);
}

int findmaxcross(int arr[],int low,int mid,int high)
{
	int maxleft=INT_MIN;
	int sumleft=0;
	for(int i=mid;i>=low;i--)
	{
		sumleft+=arr[i];
		if(sumleft>maxleft)
			maxleft=sumleft;	
		if(sumleft<0)
			sumleft=0;
	}	


	int maxright=INT_MIN;
	int sumright=0;
	for(int i=mid+1;i<=high;i++)
	{
		sumright+=arr[i];
		if(sumright>maxright)
			maxright=sumright;	
		if(sumright<0)
			sumright=0;
	}	
	
	return maxleft+maxright;

}


int findmaxsub(int arr[],int low,int high)
{
	if(low==high)
		return arr[low];
	int mid=(low+high)/2;
	return max(findmaxsub(arr,low,mid),findmaxsub(arr,mid+1,high),findmaxcross(arr,low,mid,high));
}

int main()
{
	int arr[10]={3,-1,-9,4,1,8,-4,10,-3,2};
	cout<<findmaxsub(arr,0,9)<<endl;
}
*/

/*
int raiseto(unsigned long long int a,int n,int b)
{
	unsigned long long int mul=1;
	while(n>0)
	{
		if(n&1)
			mul=(mul*a)%b;
		a=a*a;
		n>>=1;
	}
	return mul;
}
int towerColoring(int n) {
    n=raiseto(3,n,1000000007);
    n=raiseto(3,n,1000000007);
    return n;
}


int main()
{
	int n;
	cin>>n;
	cout<<towerColoring(n)<<endl;
}
*/

/*
#define PP 2000000

vector<long long> W;
vector<long long> F;
bool P[PP];

long long answer(long long n) {
    if (n == 1) return 1;
    
    F.clear();
    for(int i=0; i<W.size() and n > 1;) {
        if (n % W[i] == 0) {
            F.push_back(W[i]);
            n /= W[i];
        } else {
            i++;
        }
    }
    if (n > 1) F.push_back(n);
    
    long long total = 1, current = 1;
    for(int i=F.size()-1; i>=0; i--) {
        //cout << " " << F[i] << endl;
        current *= F[i];
        total += current;
    }
    return total;    
}

int main() {
    for(long long i=2; i<PP; i++) {
        if (P[i]) continue;
        W.push_back(i);
        for(long long j=i*i; j<PP; j+=i) {
            P[j] = true;
        }
    }

    int N;
    while(cin >> N) {
        long long total = 0;
        for(int i=0; i<N; i++) {
            long long temp; cin >> temp;
            total += answer(temp);
        }
        cout << total << endl;
    }
}
*/




/*
#define MAXN 1000000001
 

int spf[MAXN];
 
void sieve()
{
    spf[1] = 0;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
 
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void findprimes(int m,int n)
{
    for(int i=m;i<=n;i++)
        if(spf[i]==i)
            cout<<i<<endl;
    cout<<endl;
}

int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT    
   sieve();
    int T;
    int m,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>m>>n;
        findprimes(m,n);
    }
    return 0;
}
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
bool sortcols( const vector<long>& v1,const vector<long>& v2 ) 
{
 	if((unsigned long long int)(v1[0]*v1[1]*v1[2]) > (unsigned long long int)(v2[0]*v2[1]*v2[2]))
 		return true;
 	else
 	if((unsigned long long int)(v1[0]*v1[1]*v1[2]) < (unsigned long long int)(v2[0]*v2[1]*v2[2]))
 		return false;
 	else
 	{
 		if(v1[0] > v2[0])
 			return true;
 		else
 		if(v1[0] < v2[0])
 			return false;
 		else
 		{
 			if(v1[1] > v2[1])
 				return true;
 			else
 				return false;
 		}
 	}

}



void arrange(vector < vector<long> > vect)
{
    sort(vect.begin(), vect.end(),sortcols);
    
    for(int i=0;i<vect.size();i++)
	{
		for(int j=0;j<vect[0].size();j++)
			cout<<vect[i][j]<<" ";
        cout<<endl;
	}
}

int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
    int T;
    cin>>T;
    int len,bre,hei;
	vector < vector<long> > a;
	for(int i=0;i<T;i++)
	{
		vector<long> temp;
		cin>>len>>bre>>hei;
		temp.push_back(len);
		temp.push_back(bre);
		temp.push_back(hei);

		a.push_back(temp);
	}
    
    arrange(a);
    return 0;
}

*/
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
    int T;
    cin>>T;
    int len1,len2;
    int i,j;
    for(int i=0;i<T;i++)
    {
        cin>>len1>>len2;
        vector<char> a;
        vector<char> b;
        char temp;
        for(int j=0;j<len1;j++)
        {
            cin>>temp;
            temp=temp-'0';
            a.push_back(temp);
        }
        
        for(int k=0;k<len2;k++)
        {
            cin>>temp;
            temp=temp-'0';
            b.push_back(temp);
        }
        
        vector<char> res;
        char carry='0';
        carry=carry-'0';
        int p=a.size()-1;
        int q=b.size()-1;
        while(p>=0 && q>=0)
        {
            res.push_back((a[p]+b[q]+carry)%10);
            carry=(a[p]+b[q]+carry)/10;
            p--;
            q--;
        }
        
        while(p>=0)
        {
            res.push_back((a[p]+carry)%10);
            carry=(a[p]+carry)/10;
            p--;
        }
        
        while(q>=0)
        {
            res.push_back((b[q]+carry)%10);
            carry=(b[q]+carry)/10;
            q--;
        }
        res.push_back(carry);
        
        for(int t=res.size()-1;t>=0;t--)
            cout<<(int)res[t];
        cout<<endl;
        
        
    }
    return 0;
}

*/



