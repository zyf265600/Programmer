import { Directive, ElementRef } from '@angular/core';

@Directive({
  selector: '[appHover]'
})
export class HoverDirective im{

  constructor(private elementRef: ElementRef) {
    console.log(this.elementRef);
  }

}
