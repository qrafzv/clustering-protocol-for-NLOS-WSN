//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/EHE_LEACH/EHE_LEACH_Packet.msg.
//

#ifndef _EHE_LEACH_PACKET_M_H_
#define _EHE_LEACH_PACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "RoutingPacket_m.h"
// }}

/**
 * Enum generated from <tt>src/node/communication/routing/EHE_LEACH/EHE_LEACH_Packet.msg:26</tt> by nedtool.
 * <pre>
 * enum EHE_LEACH_Packet_Type
 * {
 * 
 *     EHE_LEACH_ADV_PACKET = 1;
 *     EHE_LEACH_JOIN_PACKET = 2;
 *     EHE_LEACH_TDMA_PACKET = 3;
 *     EHE_LEACH_DATA_PACKET = 4;
 * }
 * </pre>
 */
enum EHE_LEACH_Packet_Type {
    EHE_LEACH_ADV_PACKET = 1,
    EHE_LEACH_JOIN_PACKET = 2,
    EHE_LEACH_TDMA_PACKET = 3,
    EHE_LEACH_DATA_PACKET = 4
};

/**
 * Class generated from <tt>src/node/communication/routing/EHE_LEACH/EHE_LEACH_Packet.msg:34</tt> by nedtool.
 * <pre>
 * packet EHE_LEACH_Packet extends RoutingPacket
 * {
 *     int EHE_LEACH_PacketKind @enum(EHE_LEACH_Packet_Type);
 *     int schedule[];
 *     int numOfPackets;
 * }
 * </pre>
 */
class EHE_LEACH_Packet : public ::RoutingPacket
{
  protected:
    int EHE_LEACH_PacketKind_var;
    int *schedule_var; // array ptr
    unsigned int schedule_arraysize;
    int numOfPackets_var;

  private:
    void copy(const EHE_LEACH_Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EHE_LEACH_Packet&);

  public:
    EHE_LEACH_Packet(const char *name=NULL, int kind=0);
    EHE_LEACH_Packet(const EHE_LEACH_Packet& other);
    virtual ~EHE_LEACH_Packet();
    EHE_LEACH_Packet& operator=(const EHE_LEACH_Packet& other);
    virtual EHE_LEACH_Packet *dup() const {return new EHE_LEACH_Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getEHE_LEACH_PacketKind() const;
    virtual void setEHE_LEACH_PacketKind(int EHE_LEACH_PacketKind);
    virtual void setScheduleArraySize(unsigned int size);
    virtual unsigned int getScheduleArraySize() const;
    virtual int getSchedule(unsigned int k) const;
    virtual void setSchedule(unsigned int k, int schedule);
    virtual int getNumOfPackets() const;
    virtual void setNumOfPackets(int numOfPackets);
};

inline void doPacking(cCommBuffer *b, EHE_LEACH_Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, EHE_LEACH_Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef _EHE_LEACH_PACKET_M_H_

