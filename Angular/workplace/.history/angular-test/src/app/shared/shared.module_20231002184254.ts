import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { LayoutComponent } from './components/layout/layout.component';
import { FormsModule } from "@angular/forms"


@NgModule({
  declarations: [
    LayoutComponent
  ],
  imports: [
    CommonModule
  ],
  exports: [LayoutComponent]
})
export class SharedModule { }
