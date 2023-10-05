import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { DemoComponent } from './demo.component';



@NgModule({
  declarations: [
    DemoComponent
  ],
  imports: [
    CommonModule
  ],
  exports: [
    DemoComponent
  ]
})
export class DemoModule { }
