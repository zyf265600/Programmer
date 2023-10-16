import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { app-data-bondout } from './components/data-bond/data-bond.component';
import { FormsModule } from "@angular/forms"


@NgModule({
  declarations: [
    LayoutComponent
  ],
  imports: [
    CommonModule,
    FormsModule
  ],
  exports: [LayoutComponent]
})
export class SharedModule { }
