
#include <G4Orb.hh>
#include <G4Colour.hh>
#include "DetGeometry.hh"
#include <G4VisAttributes.hh>
#include <G4Cons.hh>
#include <G4Para.hh>
#include <G4Tubs.hh>
#include <G4IntersectionSolid.hh>
#include <G4SubtractionSolid.hh>
#include <G4UnionSolid.hh>
#include <iostream>

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 3 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

    G4Material *polystyrene = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
  // G4Material *YAP = nist->FindOrBuildMaterial("G4_WATER");
    G4Element *Y = nist->FindOrBuildElement("Y");
    G4Element *Al = nist->FindOrBuildElement("Al");
    G4Element *O = nist->FindOrBuildElement("O");
    G4Material *YAP = new G4Material("YAP", 5.37*g/cm3,3, kStateSolid);
     YAP->AddElement(Y,1);
     YAP->AddElement(Al,1);
     YAP->AddElement(O,3);

    std::ofstream fout("../material.txt");
    fout<<polystyrene<<'\n';
    fout<<YAP<<'\n';

    G4Tubs *scin_CH = new G4Tubs("scin_CH", 0, 2.5*cm, 5*cm, 90*deg, 360*deg);
    G4LogicalVolume *scin_CH_log = new G4LogicalVolume(scin_CH, polystyrene, "scin_CH_log");
    scin_CH_log->SetVisAttributes(G4Colour::Green());
    new G4PVPlacement(new G4RotationMatrix(90*deg,90*deg,0),G4ThreeVector(140*cm,0,0),scin_CH_log,"scin_CH_PVP",logicWorld,false,0);

    G4Tubs *scin_YAP = new G4Tubs("scin_YAP", 0, 1.25*cm, 1.25*cm, 90*deg, 360*deg);
    G4LogicalVolume *scin_YAP_log = new G4LogicalVolume(scin_YAP, YAP, "scin_YAP_log");
    scin_YAP_log->SetVisAttributes(G4Colour::Red());
    new G4PVPlacement(new G4RotationMatrix(90*deg,90*deg,0),G4ThreeVector(-140*cm,0,0),scin_YAP_log,"scin_YAP_PVP",logicWorld,false,0);

    return physWorld;
}