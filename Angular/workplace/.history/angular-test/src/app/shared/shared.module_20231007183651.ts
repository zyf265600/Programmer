import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DataBaComponent } from './components/data-bond/data-bond.component';
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
