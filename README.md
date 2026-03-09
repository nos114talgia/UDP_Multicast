# C++ UDP Multicast Demo

- **receiver**: Listens on a specific multicast group address to receive messages.
- **sender**: Sends messages to that multicast group address.

---

# Features

- Based on **UDP protocol (`SOCK_DGRAM`)**
- Supports **IPv4 Multicast**
- **One-to-many communication model**:  
  A single sender can deliver messages to all receivers joined to the group.

---


# Usage Instructions

To verify the multicast functionality, you must open **multiple terminal windows**.

---

## Step 1: Start the Receivers

Open the first terminal window and run:

```bash
./receiver
```

The program will block and wait for incoming messages.

Open a **second (or more) terminal window(s)** and run again:

```bash
./receiver
```

You can start **as many receiver instances as you like**.

---

## Step 2: Start the Sender

Open another terminal window and run:

```bash
./sender
```

---

# Expected Output

In the **sender window**, you should see:

```
Sent message: Hello, multicast!
```

Simultaneously, **all terminal windows running `./receiver`** should display:

```
Received message: Hello, multicast!
```

---



---

# License

MIT License
