#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <QLine>

namespace GRF{

	class incidenceMatrix{

		private:
			unsigned int vertexNumber;
			unsigned int edgeNumber;

		protected:
			std::vector<std::vector<int>> inMatrix;

		public:
			incidenceMatrix();
			incidenceMatrix(unsigned int v,  unsigned int e);

			std::vector<int> &operator[](unsigned int vtx);

			//Cria uma conexao entre vertices em um grafo que ja possui tamanho definido
			void makeCon(unsigned int vtx1,  unsigned int vtx2,  unsigned int edge);

			//Adiciona uma nova aresta no grafo
			void addEdge(unsigned int vtx1,  unsigned int vtx2);

			void removeEdge(unsigned int edg);

			void removeVertex(unsigned int vtx);

			unsigned int getVertexNumber();

			unsigned int getEdgeNumber();

			std::vector<int> getLoop(unsigned int key);	
			
			//Retorna uma árvore geradora para o grafo.
			incidenceMatrix getSpanningTree( unsigned int key);

			//Retorna o vértice que está ligado a vtx pela aresta edg.
			unsigned int getVertexCon(unsigned int vtx,  unsigned int i);

			//Retorna um vector contendo todas as conexões de um vértice
			std::vector<unsigned int> getEdges(unsigned int vtx);
			
			//Retorna um vector contendo todas as conexões entre dois vértices.
			std::vector<unsigned int> getEdges(unsigned int vtx1, unsigned int vtx2);

			//Retorna o par de vértices que está ligado pela aresta edg.
			std::pair<unsigned int,unsigned int> getVertex(unsigned int edg);

			unsigned int getConNum(unsigned int vtx);	

			//Printa o grafo na representação de matriz de incidência.
			void print();
	};

    class adjacencyMatrix {
        private:
            unsigned int vertexNumber;
            std::vector<std::vector<QLine*>> adjMatrix;
        public:
            adjacencyMatrix();

            void insertEdge(unsigned int i, unsigned int j, QPoint p1, QPoint p2);

            void removeVertex(unsigned int i);

            QLine* query(unsigned int i, unsigned int j);

            unsigned int getVertexNumber();

            void print(){
                for(unsigned int i = 0; i< vertexNumber; i++){
                    for(unsigned int j = 0; j<vertexNumber;j++)
                        std::cout<<adjMatrix[i][j]<<" ";

                    std::cout<<std::endl;
                }
            }
    };


}
#endif
