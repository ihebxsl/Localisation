//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;
import inet.networklayer.common.L3Address;

namespace inet;

class WhereIam extends FieldsChunk
{
    L3Address srcAddress; 
}
class AckitementFindMe extends FieldsChunk
{
	L3Address srcAddress; 
	//int rank;
}
class helloAnchor extends FieldsChunk
{
    L3Address srcAddress; 
}
class helloTarget extends FieldsChunk
{
    L3Address srcAddress; 
}
class CalculatedPos extends FieldsChunk
{
    L3Address srcAddress;
    int rank;
    double x;
    double y;
}
class AnchorData extends FieldsChunk
{
    L3Address targetAddress;
    string encryptedMsg;
    string signature;
    int rank;
   
    double x;
    double y;
    
}
class EncryptedTargetData extends FieldsChunk
{
    L3Address targetAddress;
    string encryptedMsg;
    string signature;

    // Méthodes d'accès générées automatiquement par le compilateur
    
   
   
}

