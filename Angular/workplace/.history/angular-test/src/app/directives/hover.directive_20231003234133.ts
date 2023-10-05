import { AfterViewInit, Directive, ElementRef, HostListener, Input } from '@angular/core';

interface Options{
  bgColor?: string
}
 
@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{
  @Input("appHover") Hover: Options = {}
  element: HTMLElement;

  constructor(private elementRef: ElementRef) {
    this.element = elementRef.nativeElement;
  }

  ngAfterViewInit(): void {
    this.element.style.backgroundColor = this.Hover.bgColor || "skyblue";
  }

  // 为元素添加鼠标移入事件
  @HostListener("mouseenter") enter() {d
    this.element.style.backgroundColor = "pink"
  }
	// 为元素添加鼠标移出事件
  @HostListener("mouseleave") leave() {
    this.element.style.backgroundColor = "skyblue"
  }

}
