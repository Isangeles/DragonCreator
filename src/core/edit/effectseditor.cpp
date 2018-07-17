/*
 * effectseditor.cpp
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
#include "effectseditor.h"
/**
 * @brief EffectsEditor::EffectsEditor Effects editor constructor
 * @param pathToBase String with path to XML base
 * @param gData ZipEditor for game graphic data archive
 */
EffectsEditor::EffectsEditor(string pathToBase, Module *mod, ZipEditor *gData) : BaseEditor(pathToBase, mod, gData)
{
    effects = DConnector::getEffectsFromBase(pathToBase);
}
/**
 * @brief EffectsEditor::~EffectsEditor Destrcutor of effects editor
 */
EffectsEditor::~EffectsEditor()
{
    //TODO delete something
}
/**
 * @brief EffectsEditor::newEffect Creates new effect with specified parameter and adds it to XML base
 * @param id Effect ID
 * @param type Effect type
 * @param duration Effect duration in seconds
 * @param modifiers Effect mofifiers list
 * @return True if effect was successfully added to base, false otherwise
 */
bool EffectsEditor::newEffect(string id, EffectType type, int duration, vector<Modifier> modifiers)
{
    Effect *editedEffect = new Effect(id, type, duration, modifiers);

    bool out = false;
    removeEffect(id); //removes previous effect with same ID
    out = DConnector::addEffectToBase(basePath, editedEffect);
    if(out)
    {
        effects = DConnector::getEffectsFromBase(basePath);
        return true;
    }
    else
        return false;
}
/**
 * @brief EffectsEditor::removeEffect Removes effect with specified ID from base
 * @param id ID of effect to remove
 * @return True if effect was succesfully removed, false otherwise
 */
bool EffectsEditor::removeEffect(string id)
{
    return DConnector::removeBaseObjectById(basePath, id);
}
/**
 * @brief EffectsEditor::getBaseObjects Returns all objects from open base
 * @return List with base objects
 */
vector<BaseObject *> EffectsEditor::getBaseObjects()
{
    vector<BaseObject *> objects = vector<BaseObject *>();

    for(Effect &e : *effects)
    {
        objects.push_back(&e);
    }

    return objects;
}
