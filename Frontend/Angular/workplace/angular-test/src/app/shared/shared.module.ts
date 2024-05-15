import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DataBondComponent } from './components/data-bond/data-bond.component';
import { FormsModule } from "@angular/forms"


@NgModule({
  declarations: [
    DataBondComponent
  ],
  imports: [
    CommonModule,
    FormsModule
  ],
  exports: [DataBondComponent]
})
export class SharedModule { }
