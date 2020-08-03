#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <cassert>
#include <chrono>
using namespace std;

const double INF = 1e9;

class TravelingSalesman
{
public:
    auto solve (
        const int N, 
        const vector<int> x,
        const vector<int> y)
    {
        vector<int> v;
        double Costs[1001][1001];

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                double i_x=x[i],i_y=y[i],j_x=x[j],j_y=y[j];
                Costs[i][j]=sqrt(pow(i_x-j_x,2)+pow(i_y-j_y,2));
            }
        }

        vector<int> route(N);
        for(int i=0;i<N-1;i++){
            route[i]=(i+1);
        }
        route[N-1]=0;

        random_device rnd;
        mt19937 mt(rnd());
        uniform_int_distribution<> randN(0,N-1);
        uniform_int_distribution<> rand100(0,99);
        auto start = std::chrono::system_clock::now();
        int time=10000;
        int bestscore=INF;
        while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count()<time){
            int edge1=randN(mt);
            int edge2=randN(mt);
            //edge1 != edge2
            while(1){
                edge2=randN(mt);
                if(edge1!=edge2 && edge1!=route[edge2] && edge2!=route[edge1])break;
            }
            assert(edge1<N&&edge1>=0);
            assert(edge2<N&&edge2>=0);
            assert(route[edge1]<N&&route[edge1]>=0);
            assert(route[edge2]<N&&route[edge2]>=0);

            //991->145  edge1=991 route[991][0]=145
            //4->43 edge2=4 route[4][0]=43
            double bef_edge1_cost=Costs[edge1][route[edge1]];
            double bef_edge2_cost=Costs[edge2][route[edge2]];
            double bef_cost = bef_edge1_cost+bef_edge2_cost;

            //991->4 edge1=991 route[991][0]=4
            //145->43 edge2=145 route[145][0]=43;
            double aft_edge1_cost=Costs[edge1][edge2];
            double aft_edge2_cost=Costs[route[edge1]][route[edge2]];
            double aft_cost = aft_edge1_cost+aft_edge2_cost;

            
            int t=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start).count();
            /*
            double startTmp=300000;
            double endTmp=10000;
            double temper=startTmp+(startTmp-endTmp)*t/(double)time;
            double probability = exp(-(aft_cost-bef_cost)/temper);
            bool FORCE_NEXT=probability>(double)(rand100(mt))/1.0;
            */
            double probability =exp(-abs(aft_cost-bef_cost)/(time-t));
            bool FORCE_NEXT=probability>rand100(mt)/1.0;
            FORCE_NEXT=false;
            #ifdef DEBUG
            if(FORCE_NEXT)cout<<"FORCE"<<endl;
            #endif
            if(bef_cost>aft_cost || (bef_cost<aft_cost && FORCE_NEXT))
            {
                #ifdef DEBUG
                cerr<<"edge1="<<edge1<<" "<<"route[edge1]="<<route[edge1]<<endl;
                cerr<<"edge2="<<edge2<<" "<<"route[edge2]="<<route[edge2]<<endl;          
                #endif

                //991->4 145->43
                int edge1_to=route[edge1];
                int edge2_to=route[edge2];
                
                //goalはedge2;
                //edge1_toがstart
                int hop=edge1_to;
                int nn=0;
                vector<int> nodelist;
                nodelist.push_back(edge1_to);
                while(edge2!=hop){
                    nn++;
                    assert(nn<=N);
                    hop=route[hop];
                    nodelist.push_back(hop);
                }

                for(int i=(int)nodelist.size()-1;i>0;i--){
                    route[nodelist[i]]=nodelist[i-1];
                }
                
                route[edge1]=edge2;
                route[edge1_to]=edge2_to;
                
                #ifdef DEBUG
                //1周できるかチェック
                int s_pos=0;
                for(int i=0;i<N;i++){
                    cerr<<"s_pos="<<s_pos<<endl;
                    s_pos=route[s_pos];
                }
                cerr<<"s_pos="<<s_pos<<endl;
                assert(s_pos==0);
                #endif
            }            
        }

#ifdef DEBUG
        for(int i=0;i<N;i++){
            cerr<<"route["<<i<<"]="<<route[i]<<endl;
        }
#endif

        int now=0;
        for(int i=0;i<N;i++){
            v.push_back(now);
            now=route[now];
        }
        
        return v;
    }
};

int main ()
{
    int N; 
    cin >> N;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    TravelingSalesman ts;
    vector<int> v = ts.solve(N, x, y);

    //書き込み用のファイルを宣言
	std::ofstream outputFile;
	//"vt.txt"という名前のファイルを作成	
	outputFile.open("vt.txt");

    
    for (auto vt: v) {
        //"vt.txt"にvtを書き込み
        outputFile<<vt<<endl;    
               cout << vt << endl;
    }
    outputFile.close();

    cout.flush();
    
    return 0;
}
