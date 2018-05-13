#include <iostream>
using namespace std;
class element{
	public:
	element *n;	
	int *w;
};

class glowa{
	public:
	int ilosc;
	int r;
	element *w;
	
	glowa(){
	this->ilosc=0;
	this->w=0;
	}
	
	void dodajElement(int *tab){
		element *a=new element;
		a->w = new int [this->r];
		//cout<<"***********"<<endl;
		for(int i=0;i<this->r;i++){
			a->w[i]=tab[i];
			
			//cout<<a->w[i]<<endl;
		}
		//cout<<"***********"<<endl;
		this->ilosc++;
		a->n=this->w;
		this->w=a;
		//cout<<this->w<<endl;
	}
	void wypiszElementy(){
		element *wk=this->w;
		while(wk->n){
			//cout<<wk->n;
			for(int i=0;i<this->r;i++){
				cout<<wk->w[i];
			}
			cout<<endl;
			wk=wk->n;
		}
		for(int i=0;i<this->r;i++){
				cout<<wk->w[i];
		}
			cout<<endl;
	}
	
};

class graf{
	public:
	int r; //rozmiar
	bool **w; 
	glowa hamilton;
	int *pom;
	
	public:
	graf(int r){
		pom= new int[r];
		this->r=r;
		this->hamilton.r=r;
		this->w = new bool*[r];
		for(int i=0;i<r;i++){
			pom[i]=-1;
			this->w[i] = new bool[r];
			for(int j=0;j<r;j++){
				this->w[i][j]=false;
			}
		}
		//graf co na zajeciach 
		this->w[0][1]=this->w[0][2]=this->w[0][3]=true;
		this->w[1][0]=this->w[1][2]=this->w[1][4]=true;
		this->w[2][0]=this->w[2][1]=this->w[2][4]=true;
		this->w[3][0]=this->w[3][4]=true;
		this->w[4][1]=this->w[4][2]=this->w[4][3]=true;
		}
	void pisz(){
		for(int i=0;i<this->r;i++){
			for(int j=0;j<this->r;j++){
				cout<<this->w[i][j];
			}
			cout<<endl;
		}
		return;
	}
	void cyklHamiltona(int a=0){
	
		if(this->pom[this->r-2]!=-1){
			
			pom[this->r-1]=a;
			
			if(this->w[pom[0]][pom[this->r-1]]){
				/*
				for(int i=0;i<this->r;i++){
					cout<<this->pom[i];
				}
				cout<<endl;
				*/
				this->hamilton.dodajElement(this->pom);
			}
			
			pom[this->r-1]=-1;
			return;
		}
		for(int i=0;i<this->r;i++){
	
				if(i==a||this->w[a][i]==0)
					continue;
					
				if(this->w[a][i]){
					
					bool pom=1;
					int f;
					
					for(int j=0;j<this->r;j++){
						if(this->pom[j]==i){		//czy byliœmy
							pom=0;
							f=i;
							break;
						}
						if(this->pom[j]==-1){		//reszta pusta
							pom=1;
							break;
						}
					}
					
					if(pom){
						for(int j=0;j<this->r;j++){
							if(this->pom[j]==-1){
								this->pom[j]=a;
								this->cyklHamiltona(i);
								this->pom[j]=-1;
								break;	
						}
					}
				}
			}
		}
	}
};



int main(){
	int a,b,c;
	graf graf(5);
	graf.pisz();
	graf.cyklHamiltona();
	
	graf.hamilton.wypiszElementy();
	
	return 0;
}
