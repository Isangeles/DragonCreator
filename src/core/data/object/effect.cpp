/*
 * effect.cpp
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
#include "effect.h"
/**
 * @brief Effect::Effect Effect constructor
 * @param id Effect ID
 * @param type Effect type
 * @param duration Effect duration
 * @param modifiers Modifiers for effect target
 */
Effect::Effect(string id, EffectType type, int duration, vector<Modifier> *modifiers)
{
    this->id = id;
    this->type = type;
    this->duration = duration;
    this->modifiers = modifiers;
}

Effect::~Effect()
{
    delete modifiers;
}
