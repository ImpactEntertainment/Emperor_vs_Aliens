/**
 * \file object.h
 * \brief Classe abstrata que representa o mais elementar objeto da engine.
 *
 * Um objeto elementar tem a capacidade de adicionar e remover filhos,
 * receber ou remover um pai, receber mensagens dos filhos e enviar
 * mensagens para os pais.
 * 
 * O comportamento do recebimento de mensagens e se o objeto é uma folha
 * (isto é, não tem filhos) deve ser definido nas classes que herdam Object
 * 
 * \author Edson Alves (edsonalves@unb.br)
 * \date 25/01/2012
 */
#ifndef OBJECT_H
#define	OBJECT_H

#include <cstdlib>
#include "messagehandler.h"

namespace edge {
	
	class Object : public MessageHandler {
	public:
		Object(Object *parent = NULL);
		virtual ~Object();
		
		void changeParent(Object *newParent);
		Object *getParent() const;
		bool isRoot() const;
		virtual bool isLeaf() const = 0;
		
		static MessageID addChildID;
		static MessageID removeChildID;
		
		void sendMessage(MessageID id, const void *inputs, void *outputs);
		
	private:
		Object *parent;
	};
}

#endif

