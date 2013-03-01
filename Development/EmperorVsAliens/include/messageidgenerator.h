/**
 * \file messageidgenerator.h
 * \brief Classe que gera os identificadores de mensagens.
 *
 * \author Leonn Ferreira Paiva (leonn.paiva@gmail.com)
 * \date 28/01/2012
 */
#ifndef MESSAGE_ID_GENERATOR_H
#define	MESSAGE_ID_GENERATOR_H

#include "messageid.h"

namespace edge {
	
	class MessageIDGenerator {
	public:
		static MessageID nextID();
		
	private:
		static MessageID freeID;
	};
}

#endif

