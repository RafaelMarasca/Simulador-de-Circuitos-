/********************************************************************************************
 * @file Circuit.h
 * @authors: Lucas Carvalho; Rafael Marasca Martins
 * @date: 20 04 2021
 * @brief Implementação da classe Circuit.
 * 
 * Este arquivo contém as declarações dos métodos e membros da classe Circuit.
 * 
 * A classe Circuit fornece os métodos para se interligar objetos da classe Component e
 * obter os valores relacionados a cada um destes.
 *  
 ********************************************************************************************/

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Graph.h"
#include "Component.h"

#include <vector>
#include <string>

namespace CCT{

	/*************************************************************************
	 * Implementação da classe Circuit.
	 * 
	 * Representa um circuito de componentes eletrônicos através de uma 
	 * matriz de incidência.
	 * 
	 *************************************************************************/
	class Circuit:public GRF::incidenceMatrix{

	private:
        std::vector<CMP::Component*> components;  /**< Armazena os componentes inseridos.*/
		std::vector<std::vector<int>> circuitMatrix; /**< Armazena os circuitos fundamentais do grafo.*/
		std::vector<unsigned int> chords; /**< Armazena as arestas que não estão na árvore geradora do grafo.*/

	   /******************************************************************************************
		* Atualiza os valores dos componentes.
		* 
	 	* @param currents um vector contendo os novos valores para as correntes dos componentes
	 	* @return void
	 	******************************************************************************************/
        void updateComponents(std:: vector<double> currents);
		
		/******************************************************************************************
		* Obtém os valores das correntes em cada componente e atualiza cada componente.
		*
	 	* @return void
	 	******************************************************************************************/
		void Solve();

    public:

	   /******************************************************************************************
		* Construtor para a classe Circuito.
		*
	 	* Constroi um elemento da Classe Circuit.
	 	******************************************************************************************/
		Circuit();

		/******************************************************************************************
		* Desconstrutor para a classe Circuito.
		*
	 	* Destrói um elemento da Classe Circuit.
	 	******************************************************************************************/
		~Circuit();

		/******************************************************************************************
		* Obtém os circuitos fundamentais do grafo de circuito e armazena em circuitMAtrix, bem 
		* como, atualiza o vector chords contendo as arestas que não estão contidas na árvore 
		* geradora do grafo e após isso, resolve o circuito e atualiza os valores de cada 
		* componente.
		*
	 	* @return void
	 	******************************************************************************************/
		void initialize();

	   /******************************************************************************************
		* Reseta a matriz de circuitos fundamentais contidas no vector cicuitMatrix e o vector
		* chords de arestas que não estão contidas na árvore geradora.
		*
	 	* @return void
	 	******************************************************************************************/
		void reset();

	   /******************************************************************************************
		* Adiciona um objeto da classe Component no circuito.
		*
		* Os vértices do componente representam nós com que outros componetes podem ser 
		* aadicionados, isto é, se dois componentes estão conectados, então, estes componentes
		* possuem um vértice em comum.
		* 
		* @param t tipo do componente a ser adicionado no circuito.
		* @param l etiqueta do componente a ser adicionado.
		* @param value valor associado ao componente a ser adicionado (resistência/tensão).
		* @param vtx1 número do primeiro vértice do componente.
		* @param vtx2 número do segundo vértice do componente.
		*
	 	* @return void
	 	******************************************************************************************/
        void addComponent(CMP::type t,std::string l,double value, unsigned int vtx1, unsigned int vtx2);
		
       /******************************************************************************************
		* Edita o valor de um objeto da classe Component pertencente ao circuito.
		*
		* Caso o componente esteja no circuito, altera o valor relacionado ao componente 
		* (resistência/tensão) cuja etiqueta é label.
		* 
		* @param value novo valor do componente a ser editado.
		* @param label etiqueta do componente a ser editado.
		*
	 	* @return void
	 	******************************************************************************************/
        void editComponent(std::string label, double value);

	   /******************************************************************************************
		* Edita a etiqueta de um objeto da classe Component pertencente ao circuito.
		*
		* Caso o componente esteja no circuito, altera a etiqueta do componente a ser editado.
		* 
		* @param label etiqueta do componente a ser editado.
		* @param newLabel nova etiqueta do componente a ser editado.
		*
	 	* @return void
		* 
		* @overload
	 	******************************************************************************************/
        void editComponent(std::string label, std::string newLabel);

	   /******************************************************************************************
		* Remove um objeto da classe Component pertencente ao circuito.
		*
		* Caso o componente exista no circuito, remove do circuito o componente com a etiqueta 
		* fornecida.
		* 
		* @param l etiqueta do componente a ser removido.
		*
	 	* @return void
	 	******************************************************************************************/
		void removeComponent(std::string l);

	   /******************************************************************************************
		* Retorna a tensão através de um componente.
		*
		* Caso o componente exista no circuito, retorna o valor da tensão do componente com a 
		* etiqueta fornecida.
		* 
		* @param l etiqueta do componente consultado.
		*
	 	* @return valor da tensão através do componente consultado.
	 	******************************************************************************************/
		double getVoltage(std::string l);

	   /******************************************************************************************
		* Retorna a corrente através de um componente.
		*
		* Caso o componente exista no circuito, retorna o valor da corrente através do componente 
		* com a etiqueta fornecida.
		* 
		* @param l etiqueta do componente consultado.
		*
	 	* @return valor da corrente através do componente consultado.
	 	******************************************************************************************/
		double getCurrent(std::string l);

	};
}

#endif
