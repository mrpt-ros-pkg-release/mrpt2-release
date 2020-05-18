/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */

#include "gui-precomp.h"  // Precompiled headers

#include <mrpt/gui/default_mrpt_glfw_icon.h>
#include <cstdint>
#include <vector>

// Default GLFW MRPT icon:
unsigned char* mrpt::gui::default_mrpt_glfw_icon()
{
	static std::vector<uint8_t> dat;
	if (!dat.empty()) return dat.data();

	/*  GIMP header image file format (RGB):
	 * /home/jlblanco/code/mrpt/scripts/mrpt_gui_icon_32x32.h  */
	unsigned int width = 64;
	unsigned int height = 64;
	/*  Call this macro repeatedly.  After each use, the pixel data can be
	 * extracted  */
#define HEADER_PIXEL(data, pixel)                                           \
	{                                                                       \
		pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4));         \
		pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
		pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33)));      \
		data += 4;                                                          \
	}
	static const char* header_data =
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````:'2E:'2E:'2E"
		":'2E:'2E:'2E````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````:'2E:'2E:'2E"
		":'2E:'2E````````$Q]0!!!!!!!!K[OL````````````````````````S=H*!!!!"
		"!!!!!!!!\\_`P````````````$Q]0!!!!!!!!!!!!!!!!#QM,,#QM>H:W[_PL````"
		"````````````````````$Q]0!!!!!!!!!!!!!!!!$!Q--$!Q@8V^]@(R````\\_`P"
		"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'RM<````:'2E:'2E"
		":'2E:'2E````````$Q]0!!!!!1%\"3%B)````````````````````````:76F!!!!"
		"!1%\"!!!!\\_`P````````````$Q]0!!!!!!!!!!!!!!!!!!!!!!!!!!!!(\"Q=Z/4E"
		"````````````````````$Q]0!!!!!!!!!!!!!!!!!!!!!!!!!!!!*35F[_PL\\_`P"
		"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'RM<````:'2E:'2E"
		":'2E````````````$Q]0!!!!1U.$!A)#YO,C````````````````^04U$1U./$AY"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@`````P\\_Z_@HHJ[?$1U.!!!!:G:G"
		"````````````````````$Q]0!!!!X^`@`````P\\_ZO<GFJ;7#!A)!!!!<W^P````"
		"````````````````````8V^@!!!!CYO,````````````````````````````:'2E"
		":'2E````````````$Q]0!!!!JK;G!!!!AI+#````````````````HJ[?!!!!GZO<"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````CYO,!!!!)C)C"
		"````````````````````$Q]0!!!!X^`@````````````````B97&!!!!*C9G````"
		"````````````````````8V^@!!!!CYO,````````````````````````````:'2E"
		":'2E````````````$Q]0!!!![OLK(R]@)#!A`P\\_````````````/DI[#QM,]`0T"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````O,CY!!!!%R-4"
		"````````````````````$Q]0!!!!X^`@````````````````N\\?X!!!!%2%2````"
		"````````````````````8V^@!!!!CYO,````````````````````````````:'2E"
		":'2E````````````$Q]0!!!![_PLA)#!!!!!P,S]````````VN<7!!!!9G*C````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````C)C)!!!!-4%R"
		"````````````````````$Q]0!!!!X^`@````````````````BI;'!!!!*C9G````"
		"````````````````````8V^@!!!!CYO,````````````````````````````:'2E"
		"````````````````$Q]0!!!![_PLY?(B!A)#76F:````````=X.T!!!!R=8&````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@`````P\\_[/DIH:W>#QM,!!!!E:'2"
		"````````````````````$Q]0!!!!X^`@`````P\\_Z_@HG*C9#1E*!!!!<W^P````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````2E:'#!A)\\O\\O_PL[&256+3EJ````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!!!!!!!!!!!!!!!!!!!!!\"15&=8&R`P\\_"
		"````````````````````$Q]0!!!!!!!!!!!!!!!!!!!!!!!!!!!!*#1E[_PL````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````K;GJ!!!!EZ/4K[OL!!!!D)S-````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!!!!!!!!!!!!!!!!!!!!!-T-TYO,C````"
		"````````````````````$Q]0!!!!!!!!!!!!!!!!#QM,,S]P@(R]]0$Q````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````_@HZ%R-4-$!Q2U>(\"15&[?HJ````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````_PL[V^@86V>8!!!!*C9G]`0T"
		"````````````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````````<W^P!!!!!1%\"5V.4````````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@`````````````@X^1E*#!!!!>86V"
		"````````````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````````UN,3!!!!!!!!NL;W````````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````W>H:\"!1%\"Q=("
		"Y/$A````````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````````````````````````````````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````````;7FJ!!!!"
		"86V>````````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````````````````````````````````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````````[/DI#QM,"
		"!A)#U>(2````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````$Q]0!!!![_PL````````````````````````````````````"
		"#QM,!!!!\\_`P````````````$Q]0!!!!X^`@````````````````````````@HZ_"
		"!!!!35F*````````````$Q]0!!!!X^`@````````````````````````````````"
		"````````````````````8V^@!!!!CYO,````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````]`0`^`@`````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````45X`!!$`!!$`!!$`"
		"$A\\`NL<`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````2E<`!!$`!!$`!!$`"
		"!!$`O,D`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````1%$`!!$`!!$`!!$`"
		"!!$`PL\\`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````/DL`!!$`!!$`!!$`"
		"!!$`R=8`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````-T0`!!$`!!$`!!$`"
		"!!$`S]P`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````,3X`!!$`!!$`!!$`"
		"!!$`U>(`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````*S@`!!$`!!$`!!$`"
		"!!$`W.D`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````)#$`!!$`!!$`!!$`"
		"!!$`XN\\`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````'BL`!!$`!!$`!!$`"
		"!!$`Z/4`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````&\"4`!!$`!!$`!!$`"
		"!!$`[_P`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````$1X`!!$`!!$`!!$`"
		"!!$`]@(`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````\"Q@`!!$`!!$`!!$`"
		"!!$`^`@`````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````!1(`!!$`!!$`!!$`"
		"!!$`SPX-T0`-T0`-T0`-T0`-T0`-T0`-T0`-T0`-T0`-T@`.X@`>X@`>X@`>X@`>"
		"X@`>X@`>ZP`G````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````_P8[!!$`!!$`!!$`!!$`"
		"!!8[!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!"
		"!0]!!0]!20^%````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"``````````````````````````````````````````\\__6^F:A#::A#:'%'F!&7K"
		"!&OE!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!"
		"!0]!!0]!2@^&````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"`````````````````````````````````````````XJ[`Q!!`Q!!`Q!!2<I!!0]!"
		"!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!"
		"!0]!!0]!2P^'````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"`````````````````````````````````````ZC9`Q!!`Q!!`Q!!`Q!!2,M!!0]!"
		"!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!!0]!"
		"!0]!!0]!2`^(````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"`````````````````````````````````\\+S`Q-$`Q!!`Q!!`Q!!`Q!!;:9!-OI?"
		"-`]T-`]T-`]T-`]T-`]T-`]T-`]T-`]T-`]T-`]T-`]T-@]R)P]C)P]C)P]C)P]C"
		")P]C)P]C9@^B````````````````````````````````````````````````````"
		":'2E````````````````````````````````````````````````````````````"
		"`````````````````````````````]D)`QI+`Q!!`Q!!`Q!!`Q!!`Q!!`Y'\"````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E````````````````````````````````````````````````````````````"
		"`````````````````````````^86`R)3`Q!!`Q!!`Q!!`Q!!`Q!!`W2E````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E````````````````````````````````````````````````````````````"
		"`````````````````````_8F`R]@`Q!!`Q!!`Q!!`Q!!`Q!!`UN,``P\\````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E````````````````````````````````````````````````````````````"
		"``````````````````(R`S]P`Q!!`Q!!`Q!!`Q!!`Q!!`T9W``4U````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E:'2E````````````````````````````````````````````````````````"
		"``````````````HZ`U2%`Q!!`Q!!`Q!!`Q!!`Q!!`S1E`_HJ````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````:'2E:'2E"
		":'2E:'2E````````````````````````````````````````````````````````"
		"``````````\\_`VR=`Q!!`Q!!`Q!!`Q!!`Q!!`RE:`^`@````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````:'2E:'2E"
		":'2E:'2E:'2E````````````````````````````````````````````````````"
		"`````````X\"Q`Q!!`Q!!`Q!!`Q!!`Q!!`QU.`]\\/````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````:'2E:'2E:'2E"
		":'2E:'2E:'2E````````````````````````````````````````````````````"
		"`````YG*`Q!!`Q!!`Q!!`Q!!`Q!!`Q5&`\\GZ````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E````````````````````````````````````````````````"
		"`[?H`Q)#`Q!!`Q!!`Q!!`Q!!`Q%\"`['B````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E````````````````````````````````````````````"
		"`]<'`R-4`Q!!`Q!!`Q!!`Q!!`YS-````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````````````"
		"`````^45`RY?`Q!!`Q!!`WJK````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````````"
		"`````````_8F`S]P`V:7``X^````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````````"
		"`````````````_`P``DY````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````````"
		"````````````:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E````````"
		"````````````````````````````````````````````````````````````````"
		"````````````````````````````````````````````````````````````:'2E"
		":'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E:'2E"
		"";

	// GLFW image format: RGBA
	dat.resize(width * height * 4);
	const char* in = header_data;
	uint8_t* out = dat.data();
	const uint8_t transp = 100;  // transparent color

	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			// RGB
			HEADER_PIXEL(in, out);
			// alpha
			out[3] = (out[0] == transp && out[1] == transp && out[2] == transp)
						 ? 0x00
						 : 0xff;
			out += 4;
		}
	}
	return dat.data();

#undef HEADER_PIXEL
}
