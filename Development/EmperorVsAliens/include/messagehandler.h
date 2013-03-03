/**
 * \file messagehandler.h
 * \brief Interface para recebimento e envio de mensagens.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 28/01/2012
 */
#ifndef MESSAGE_HANDLER_H
#define	MESSAGE_HANDLER_H

#include "messageid.h"

namespace edge {
	
	class MessageHandler {
	public:
		virtual void
		sendMessage(MessageID id, const void *inputs, void *outputs) = 0;
		
		virtual void
		receiveMessage(MessageID id, void *sender, const void *inputs,
			void *outputs) = 0;
		
	};
}

#endif

