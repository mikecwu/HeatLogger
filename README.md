The projects main objective is to develop a monitoring device that can record and store
temperature and humidity readings. The final product has to be able to be operated both
from the interface on the device and remotely from a computer. The device can perform
two modes which one is Snapshot mode that takes a single reading and the other is Stream
mode that constantly takes readings.

The hardware section of the product is consisting of a computation FPGA board
that is assembled with the sensor board and the alarm module. It runs on VHDL codes that
are controlled by state machines. The USB Protocol on the hardware needs to be design
with the sample VHDL code to work with the software on the PC. The software is designed
using C++ with Qt that uses Dynamic-link library, or also know as DLL, to communicate
with the board.

The software section is extremely easy to implement once the provided DLL is setup
to use command-line programs. The software can retrieve the data fast enough to display
on the screen in graph or just displaying current reading. However, the hardware is hard
to implement especially merging all the components under the same clock cycle. We lessen
the difficulties by moving a bit of the hardware section to the software section as seen in
our USB Protocol. The packet sent by the hardware is basically what the data that the
hardware reads from the sensors so it is up to the software to convert the raw data which
C++ works really well with byte data and the bitwise commands.