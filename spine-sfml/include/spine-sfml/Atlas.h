/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#ifndef SPINE_ATLAS_H_
#define SPINE_ATLAS_H_

#include <spine/BaseAtlas.h>
#include <SFML/Graphics/Texture.hpp>

namespace spine {

class AtlasPage: public BaseAtlasPage {
public:
	~AtlasPage ();

	sf::Texture *texture;
};

//

class AtlasRegion: public BaseAtlasRegion {
public:
	AtlasPage *page;
};

//

class Atlas: public BaseAtlas {
public:
	Atlas (std::ifstream &file);
	Atlas (std::istream &input);
	Atlas (const std::string &text);
	Atlas (const char *begin, const char *end);

	AtlasRegion* findRegion (const std::string &name);

private:
	virtual BaseAtlasPage* newAtlasPage (const std::string &name);
	virtual BaseAtlasRegion* newAtlasRegion (BaseAtlasPage* page);
};

} /* namespace spine */
#endif /* SPINE_ATLAS_H_ */
