#ifndef  TWI_PRIVATE_H_
#define  TWI_PRIVATE_H_
/*********************************************************************************/
/************************     Author: Khaled Mustafa    **************************/
/************************     SWC: TWI                  **************************/
/*********************************************************************************/

#define START_ACK					0x08 	/* Start has been sent */
#define	REP_START_ACK				0x10	/* Repeated start */
#define SLAVE_ADD_AND_W_ACK			0x18 	/* Master transmit (slave address + W) */
#define SLAVE_ADD_AND_R_ACK			0x40 	/* Master transmit (slave address + R) */
#define MSTR_W_BYTE_ACK				0x28 	/* master transmit data ACK */
#define MSTR_R_BYTE_WITH_ACK 		0x50	/* master recieved data with ACK */
#define MSTR_R_BYTE_WITH_NOTACK 	0x58 	/* master recieved data with not ACK */
#define SLAVE_ADD_RCVD_R_REQ		0xA8 	/* slave address is recieved with read request */
#define SLAVE_ADD_RCVD_W_REQ		0x60 	/* slave address is recieved with write request */
#define SLAVE_DATA_RECEIVED			0x80 	/* byte is received */
#define SLAVE_BYTE_TRANSMITTED 		0xB8 	/* written byte is transmitted */

#endif
