/*
 * effect.h
 * Copyright (C) 2018 Dariusz Sikora<darek@pc-solus>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>

#include "baseobject.h"
#include "src/core/data/object/modifier.h"

using namespace std;

enum EffectType {NORMAL = 0, MAGIC = 1, FIRE = 2, ICE = 3, NATURE = 4};
/**
 * @brief Class for effects
 */
class Effect : public BaseObject
{
friend class EffectParser;
public:
    Effect(string id, EffectType type, int duration, vector<Modifier> *modifiers);
    ~Effect();
    string getId();
    EffectType getType();
    int getDuration();
    vector<Modifier> *getModifiers();
private:
    string id;
    EffectType type;
    int duration;
    vector<Modifier> *modifiers;
};

#endif // EFFECT_H
