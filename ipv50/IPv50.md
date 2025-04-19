# IPv50 – A theoretical 50-Bit IP addressing system 

**IPv50** (or _IPv550_; not quite sure what to call it lol) is a fictional network addressing model using **50-bit** IP addresses. It was created to demonstrate and explain the structure of existing IPv4 and IPv6 adressing and how it could theoretically be extended.

---

## What is IPv50?

IPv50 uses **5 octet-like fields**, where each field can hold values from **0 to 512**. This provides an address space of:

(513)^5 ≈ 1,168,526,261,121 unique addresses

### Example addresses

- 10.50.100.200.300  
- 0.0.0.0.0 *(Network base address)*  
- 512.512.512.512.512 *(Broadcast in IPv50)*

---

## IPv50 address structure

| Field | Bits   | Range   |
|-------|--------|---------|
| 1     | 10 Bit | 0–512   |
| 2     | 10 Bit | 0–512   |
| 3     | 10 Bit | 0–512   |
| 4     | 10 Bit | 0–512   |
| 5     | 10 Bit | 0–512   |
| **Total** | **50 Bit** | ~1.17 trillion addresses |

---

## IPv4 backward compatibility

To ensure IPv4 compatibility, a simple mapping is used:

IPv4: A.B.C.D → IPv50: 0.A.B.C.D

### example:

- IPv4 `192.168.1.1` becomes IPv50 `0.192.168.1.1`
- The address ranges `0.*.*.*.*` and `0.255.*.*.*` are **reserved** for IPv4-compatible addresses

---

## motivation

i had to come up with sth for a presentation lol

## ideas for future development

- subnet masks for IPv50
- basic routing table simulation
- NAT-like translation between IPv50 and IPv4
- simulated UDP/TCP behavior

